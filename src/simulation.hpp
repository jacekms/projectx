#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "infra/infra.hpp"
#include "mining_truck.hpp"
#include "mining_unload_station.hpp"
#include "random_duration_generator.hpp"
#include "event_sequencer.hpp"
#include "stats/simulation_stats.hpp"

#include <vector>

namespace SimH3Mining {

class Simulation : public SimulationStats
{
private:
    int max_mining_trucks;
    int max_unload_stations;
    std::chrono::minutes max_simulation_time;

    /// doxy docs
    /// \relates MiningTruck
    ///MiningTruck trucks[...]
    /// \relates MiningUnloadStation
    ///MiningUnloadStation stations[...]

    std::vector<MiningTruck> trucks;
    std::vector<MiningUnloadStation> stations;

    RandomDurationGenerator duration_generator;
    EventSequencer event_sequencer;

public:
    Simulation(int mining_trucks, int unload_stations, std::chrono::minutes simulation_time);
    void run();
    void queue_truck_for_unloading(MiningTruck* truck);
    void schedule_next_event();
    void report_statistics() const;
    MiningUnloadStation* find_shortest_wait_time_station();
    bool try_unloading_truck(Infra::SH3M_SimStepClock::time_point nearest_event_time);
    MiningUnloadStation* find_nearest_truck_unload_time();

};

} // namespace SimH3Mining

#endif // SIMULATION_HPP

