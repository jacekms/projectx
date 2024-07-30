#ifndef MINING_TRUCK_STATS_HPP
#define MINING_TRUCK_STATS_HPP

#include <chrono>

namespace SimH3Mining {

class MiningTruckStats {
private:
    int total_operation_cycles;
    std::chrono::minutes total_wait_time_in_unload_queues;
    std::chrono::minutes total_travel_time;
    std::chrono::minutes total_mining_time;
    static inline std::chrono::minutes total_simulation_time = std::chrono::minutes(0);


public:
    MiningTruckStats();

    static void register_total_simulation_time(std::chrono::minutes time);

    void add_operation_cycle();
    void add_wait_time_in_unload_queues(std::chrono::minutes time);
    void add_travel_time(std::chrono::minutes time);
    void add_mining_time(std::chrono::minutes time);

    int get_total_operation_cycles() const;
    std::chrono::minutes get_total_wait_time_in_unload_queues() const;
    std::chrono::minutes get_total_travel_time() const;
    std::chrono::minutes get_total_mining_time() const;
    double get_avg_wait_time_in_unload_queues() const;
    double get_avg_mining_time() const;
    double get_mining_to_sim_time_ratio() const;

    void print_statistics() const;
};

} // namespace SimH3Mining

#endif // MINING_TRUCK_STATS_HPP

