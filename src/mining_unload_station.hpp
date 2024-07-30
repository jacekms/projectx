#ifndef MINING_UNLOAD_STATION_HPP
#define MINING_UNLOAD_STATION_HPP

#include <queue>
#include "mining_truck.hpp"
#include "stats/unload_station_stats.hpp"

namespace SimH3Mining {

class MiningUnloadStation : public UnloadStationStats {
private:
    int id;

public:
    Infra::SH3M_SimStepClock::time_point nearest_time_to_unload;

    struct Truck_Info {
        MiningTruck* truck;
        Infra::SH3M_SimStepClock::time_point unload_time;
    };

    std::queue<Truck_Info> queue;

    MiningUnloadStation(int id);

    int get_id() const { return id; }

    void add_to_queue(MiningTruck* truck);
    void process_queue();
};

} // namespace SimH3Mining

#endif // MINING_UNLOAD_STATION_HPP
