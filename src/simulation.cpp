#include "simulation.hpp"
#include "infra/infra.hpp"
#include "infra/sh3m_assert.hpp"
#include "stats/unload_station_stats.hpp"
#include "stats/mining_truck_stats.hpp"

#include <algorithm>
#include <stdexcept>

namespace SimH3Mining {

Simulation::Simulation(int mining_trucks, int unload_stations,
                       std::chrono::minutes simulation_time) :
    max_mining_trucks(mining_trucks),
    max_unload_stations(unload_stations),
    max_simulation_time(simulation_time)
{
    // Set the total simulation time for statistics collection
    UnloadStationStats::register_total_simulation_time(max_simulation_time);
    MiningTruckStats::register_total_simulation_time(max_simulation_time);

    // Create and initialize truck and station objects
    for (int i = 0; i < max_mining_trucks; ++i) {
        trucks.emplace_back(i);
    }
    for (int i = 0; i < max_unload_stations; ++i) {
        stations.emplace_back(i);
    }
}

// Executes simulation
void Simulation::run()
{
    auto sim_start_time = Infra::SH3M_SimStepClock::now();
    Infra::SH3M_SimStepClock::time_point sim_end_time = sim_start_time + max_simulation_time;

    // Main simulation loop
    while (Infra::SH3M_SimStepClock::now() < sim_end_time)
    {
        logger.log("Sim: time now=%" PRIi64 " < end=%" PRIi64 "\n",
                    Infra::SH3M_SimStepClock::now().time_since_epoch().count(),
                    sim_end_time.time_since_epoch().count());


        auto next_event_opt = event_sequencer.get_next_event();
        if (!next_event_opt.has_value()) {
            schedule_next_event();
            continue;
        }

        Event next_event = next_event_opt.value();

        auto time_now = Infra::SH3M_SimStepClock::now();

        SH3M_ASSERT2(time_now <= next_event.time, "Truck%u %ld <= %ld\n",
                     next_event.truck->get_id(), time_now, next_event.time);

        logger.log("Sim: Time step now=%" PRIu64 " new_time=%" PRIu64 "\n",
                   time_now, next_event.time);

        Infra::SH3M_SimStepClock::set_time(next_event.time);

        next_event.execute();

        logger.log("Sim: Truck%u executed event in [%s] state\n",
                    next_event.truck->get_id(),
                    next_event.truck->get_state_name(next_event.truck->get_state()));

        queue_truck_for_unloading(next_event.truck);

        schedule_next_event();
    }

    logger.log("Simulation done after %d min\n", max_simulation_time);
    report_statistics();

}

void Simulation::queue_truck_for_unloading(MiningTruck* truck)
{
    SH3M_ASSERT(truck != nullptr);

    if (truck->get_state() != MiningTruck::State::WaitingInQueue) {
        return;
    }

    MiningUnloadStation* station = find_shortest_wait_time_station();
    SH3M_ASSERT(station != nullptr);

    logger.log("Sim: Station%u queue add Truck%u, nearest unload start time=%" PRIu64 "\n",
               station->get_id(),
               truck->get_id(),
               station->nearest_time_to_unload);

    station->add_to_queue(truck);

}

void Simulation::schedule_next_event()
{
    // Find the nearest event time_point across all trucks

    auto it = trucks.begin();
    SH3M_ASSERT(it != trucks.end());  // Check iterator is valid before dereferencing

    MiningTruck* next_truck = &(*it); // Get first truck

    Infra::SH3M_SimStepClock::time_point nearest_event_time =
            next_truck->get_time_of_next_event();

    for (auto& truck : trucks)  //TODO use iterator
    {
        Infra::SH3M_SimStepClock::time_point event_time =
                truck.get_time_of_next_event();

        if (event_time < nearest_event_time) {
            nearest_event_time = event_time;
            next_truck = &truck;
        }
    }

    SH3M_ASSERT(next_truck != nullptr); // There must be an event


    if (next_truck) {
        logger.log("Sim: Truck%u nearest event in state [%s] time=%" PRIu64 "\n",
                    next_truck->get_id(),
                    next_truck->get_state_name(next_truck->get_state()),
                    nearest_event_time);

        event_sequencer.schedule_event(Event(nearest_event_time, next_truck));
    }

    // Check if any station can earlier finish unloading a truck
    (void)try_unloading_truck(nearest_event_time);
}


void Simulation::report_statistics() const
{
    logger.log("========================= STATISTICS ========================\n");
    logger.log("Simulation\n");
    this->print_statistics();

    for (const auto& truck : trucks) {
        logger.log("Truck%d\n", truck.get_id());
        truck.print_statistics();
    }
    for (const auto& station : stations) {
        logger.log("Station%d\n", station.get_id());
        station.print_statistics();
    }
}

MiningUnloadStation* Simulation::find_shortest_wait_time_station()
{
    return &*std::min_element(stations.begin(), stations.end(),
        [](const MiningUnloadStation& a, const MiningUnloadStation& b) {
            return a.nearest_time_to_unload < b.nearest_time_to_unload;
        //return a.queue.size() < b.queue.size();
        });
}

bool Simulation::try_unloading_truck(Infra::SH3M_SimStepClock::time_point nearest_event_time)
{
    // Truck stays in queue during unload process
    MiningUnloadStation* station = find_nearest_truck_unload_time();
    if (station == nullptr) {
        return false;  // no queued trucks
    }

    SH3M_ASSERT(not station->queue.empty());
    auto nearest_unload_time = station->queue.front().unload_time;
    MiningTruck* truck = station->queue.front().truck;
    SH3M_ASSERT(truck != nullptr);

    if (nearest_unload_time <= nearest_event_time)
    {
        logger.log("Sim: Station%d Unloaded Truck%u state [%s] time=%" PRIu64 "\n",
                   station->get_id(),
                   truck->get_id(),
                   truck->get_state_name(truck->get_state()),
                   nearest_unload_time);

        station->process_queue();

        Infra::SH3M_SimStepClock::set_time(nearest_unload_time);

        return true; // unloaded truck event
    }

    return false;
}


MiningUnloadStation* Simulation::find_nearest_truck_unload_time()
{
    auto it = std::min_element(stations.begin(), stations.end(),
        [](const MiningUnloadStation& a, const MiningUnloadStation& b) {
            if (a.queue.empty()) return false;
            if (b.queue.empty()) return true;

            return a.queue.front().unload_time < b.queue.front().unload_time;

        });

    // If all stations queues are empty return nullptr
    if (it == stations.end() || it->queue.empty()) {
        // Handle the case where no valid station is found
        return nullptr;
    }

    return &(*it);
}


} // namespace SimH3Mining
