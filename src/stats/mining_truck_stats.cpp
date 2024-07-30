#include "mining_truck_stats.hpp"
#include "../infra/infra.hpp"
#include <cstdio>

namespace SimH3Mining {

MiningTruckStats::MiningTruckStats() :
    total_operation_cycles(0),
    total_wait_time_in_unload_queues(0),
    total_travel_time(0),
    total_mining_time(0)
{}

void MiningTruckStats::add_operation_cycle() {
    this->total_operation_cycles++;
}

void MiningTruckStats::add_wait_time_in_unload_queues(std::chrono::minutes time) {
    this->total_wait_time_in_unload_queues += time;
}

void MiningTruckStats::add_travel_time(std::chrono::minutes time) {
    this->total_travel_time += time;
}

void MiningTruckStats::add_mining_time(std::chrono::minutes time) {
    this->total_mining_time += time;
}

void MiningTruckStats::register_total_simulation_time(std::chrono::minutes time) {
    total_simulation_time = time;
}

int MiningTruckStats::get_total_operation_cycles() const {
    return this->total_operation_cycles;
}

std::chrono::minutes MiningTruckStats::get_total_wait_time_in_unload_queues() const {
    return this->total_wait_time_in_unload_queues;
}

std::chrono::minutes MiningTruckStats::get_total_travel_time() const {
    return this->total_travel_time;
}

std::chrono::minutes MiningTruckStats::get_total_mining_time() const {
    return this->total_mining_time;
}

double MiningTruckStats::get_avg_wait_time_in_unload_queues() const {
    return this->total_operation_cycles > 0 ?
                static_cast<double>(this->total_wait_time_in_unload_queues.count())
                / static_cast<double>(this->total_operation_cycles) : 0.0;
}

double MiningTruckStats::get_avg_mining_time() const {
    return this->total_operation_cycles > 0 ?
                static_cast<double>(this->total_mining_time.count())
                / static_cast<double>(this->total_operation_cycles) : 0.0;
}

double MiningTruckStats::get_mining_to_sim_time_ratio() const {
    return total_simulation_time.count() > 0 ?
                static_cast<double>(this->total_mining_time.count())
                / static_cast<double>(total_simulation_time.count()) : 0.0;
}

void MiningTruckStats::print_statistics() const {
    logger.log("Total Operation Cycles: %d\n", this->total_operation_cycles);
    logger.log("Total Wait Time in Unload Queues: %ld minutes\n",
               this->total_wait_time_in_unload_queues.count());
    logger.log("Average Wait Time in Unload Queues: %.2f minutes\n",
               get_avg_wait_time_in_unload_queues());
    logger.log("Total Travel Time: %ld minutes\n", this->total_travel_time.count());
    logger.log("Total Mining Time: %ld minutes\n", this->total_mining_time.count());
    logger.log("Average Mining Time: %.2f minutes\n", get_avg_mining_time());
    logger.log("Mining to Simulation Time Ratio: %.2f%%\n", get_mining_to_sim_time_ratio() * 100);
}

} // namespace SimH3Mining
