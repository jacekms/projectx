#include "mining_unload_station.hpp"
#include "infra/infra.hpp"

namespace SimH3Mining {

MiningUnloadStation::MiningUnloadStation(int idx) :
    id(idx), nearest_time_to_unload()
{}

void MiningUnloadStation::add_to_queue(MiningTruck* truck)
{
    SH3M_ASSERT(truck != nullptr);

    auto time_now = Infra::SH3M_SimStepClock::now();

    // Add unload time to time_now if queue empty or extend current wait time for unload
    this->nearest_time_to_unload = max(time_now, this->nearest_time_to_unload)
            + truck->get_unload_duration();

    this->add_queue_used_time(truck->get_unload_duration());

    // Passing to the truck time end of queue time wait + unload
    truck->update_time_of_unload(this->nearest_time_to_unload);
    this->increment_queued();

    logger.log("Sim: To Station%d %s QLen=%zu ADD Truck%u [%s] unload finish time=%lu\n",
               this->id,
               this->queue.size() ? "occupied" : "not occupied",
               this->queue.size(), truck->get_id(),
               truck->get_state_name(truck->get_state()),
               this->nearest_time_to_unload.time_since_epoch().count());



    truck->queue_to_unload();

    this->queue.push({truck, this->nearest_time_to_unload});
}

void MiningUnloadStation::process_queue()
{
    if (not this->queue.empty()) {
        this->increment_unloads();
        this->queue.pop();
    }
}

} // namespace SimH3Mining
