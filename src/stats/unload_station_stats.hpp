#ifndef UNLOAD_STATION_STATS_HPP
#define UNLOAD_STATION_STATS_HPP

#include "../infra/infra.hpp"

#include <chrono>

namespace SimH3Mining {

class UnloadStationStats {
private:
    int total_queued;
    int total_unloads;
    std::chrono::minutes total_queue_used_time;
    static inline std::chrono::minutes total_simulation_time = std::chrono::minutes(0);

public:
    UnloadStationStats();

    static void register_total_simulation_time(std::chrono::minutes time);

    void increment_queued();
    void increment_unloads();
    void add_queue_used_time(std::chrono::minutes time);

    int get_total_unloads() const;
    std::chrono::minutes get_total_queue_used_time() const;
    double get_avg_queue_used_time() const;
    double get_operation_time_to_no_op_ratio() const;

    void print_statistics() const;
};

} // namespace SimH3Mining

#endif // UNLOAD_STATION_STATS_HPP

