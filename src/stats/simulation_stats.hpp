#ifndef SIMULATION_STATS_HPP
#define SIMULATION_STATS_HPP

#include "../infra/infra.hpp"

#include <chrono>

namespace SimH3Mining {

class SimulationStats {
private:
    int total_unloads;
    std::chrono::minutes total_mine_time;
    std::chrono::minutes total_wait_in_unload_queue;
    int total_operation_cycles;

public:
    SimulationStats();

    void increment_unloads();
    void add_mine_time(std::chrono::minutes time);
    void add_wait_in_unload_queue(std::chrono::minutes time);
    void add_operation_cycle();

    int get_total_unloads() const;
    std::chrono::minutes get_total_mine_time() const;
    std::chrono::minutes get_total_wait_in_unload_queue() const;
    int get_total_operation_cycles() const;

    void print_statistics() const;
};

} // namespace SimH3Mining


#endif // SIMULATION_STATS_HPP

