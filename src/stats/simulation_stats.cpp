#include "simulation_stats.hpp"
#include <cstdio>

namespace SimH3Mining {

SimulationStats::SimulationStats()
    : total_unloads(0), total_mine_time(0), total_wait_in_unload_queue(0), total_operation_cycles(0) {}

void SimulationStats::increment_unloads() {
    this->total_unloads++;
}

void SimulationStats::add_mine_time(std::chrono::minutes time) {
    this->total_mine_time += time;
}

void SimulationStats::add_wait_in_unload_queue(std::chrono::minutes time) {
    this->total_wait_in_unload_queue += time;
}

void SimulationStats::add_operation_cycle() {
    this->total_operation_cycles++;
}

int SimulationStats::get_total_unloads() const {
    return this->total_unloads;
}

std::chrono::minutes SimulationStats::get_total_mine_time() const {
    return this->total_mine_time;
}

std::chrono::minutes SimulationStats::get_total_wait_in_unload_queue() const {
    return this->total_wait_in_unload_queue;
}

int SimulationStats::get_total_operation_cycles() const {
    return this->total_operation_cycles;
}

void SimulationStats::print_statistics() const {
    logger.log("Total Unloads: %d\n", this->total_unloads);
    logger.log("Total Mine Time: %ld minutes\n", this->total_mine_time.count());
    logger.log("Total Wait in Unload Queue: %ld minutes\n", this->total_wait_in_unload_queue.count());
    logger.log("Total Operation Cycles: %d\n", this->total_operation_cycles);
}

} // namespace SimH3Mining
