#include "unload_station_stats.hpp"
#include <cstdio>

namespace SimH3Mining {

UnloadStationStats::UnloadStationStats()
    : total_queued(0), total_unloads(0), total_queue_used_time(0)
{}

void UnloadStationStats::register_total_simulation_time(std::chrono::minutes time) {
    total_simulation_time = time;
}

void UnloadStationStats::increment_queued() {
    this->total_queued++;
}

void UnloadStationStats::increment_unloads() {
    this->total_unloads++;
}

void UnloadStationStats::add_queue_used_time(std::chrono::minutes time) {
    this->total_queue_used_time += time;
}


int UnloadStationStats::get_total_unloads() const {
    return this->total_unloads;
}

std::chrono::minutes UnloadStationStats::get_total_queue_used_time() const {
    return this->total_queue_used_time;
}

double UnloadStationStats::get_avg_queue_used_time() const {
    return this->total_unloads > 0 ?
                static_cast<double>(this->total_queue_used_time.count()) /
                static_cast<double>(this->total_unloads) : 0.0;
}

double UnloadStationStats::get_operation_time_to_no_op_ratio() const {
    return total_simulation_time.count() > 0 ?
                static_cast<double>(this->total_queue_used_time.count()) /
                static_cast<double>(total_simulation_time.count()) : 0.0;
}

void UnloadStationStats::print_statistics() const {
    logger.log("Total Unloads: %d\n", this->total_unloads);
    logger.log("Total Queue Used Time: %ld minutes\n", this->total_queue_used_time.count());
    logger.log("Average Queue Used Time: %.2f minutes\n", get_avg_queue_used_time());
    logger.log("Operation Time to No-Op Ratio: %.2f%%\n", get_operation_time_to_no_op_ratio() * 100);
}

} // namespace SimH3Mining
