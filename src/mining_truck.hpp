#ifndef MINING_TRUCK_HPP
#define MINING_TRUCK_HPP

#include "infra/infra.hpp"
#include "stats/mining_truck_stats.hpp"

#include <chrono>
#include <cstdio>
#include <random>

namespace SimH3Mining {

class MiningTruck : public MiningTruckStats
{
public:

    ///TODO use Magic Enum or FSM_lib
    enum class State : uint8_t {
        Mining,
        TravelingToUnload,
        WaitingInQueue,
        Unloading,
        TravelingToMine
    };
    const char* get_state_name(State idx)
    {
        const char* names[] = {
            "Mining",
            "TravelingToUnload",
            "WaitingInQueue",
            "Unloading",
            "TravelingToMine"
        };
        return names[static_cast<uint8_t>(idx)];
    }

private:
    enum MiningTruckCfg : uint32_t {
        TRAVEL_TIME = 30, // minutes
        UNLOAD_TIME = 5,  // minutes
        MINING_TIME_DISTRIBUTION_MIN = 50, // minutes
        MINING_TIME_DISTRIBUTION_MAX = (5 * 60), // minutes
    };

    int id;
    State current_state;

    std::chrono::minutes mining_time;
    std::chrono::minutes travel_time;
    std::chrono::minutes wait_in_queue_time;
    std::chrono::minutes unload_time;

    Infra::SH3M_SimStepClock::time_point time_of_finished_unload;
    std::chrono::minutes time_to_next_event;
    Infra::SH3M_SimStepClock::time_point time_of_next_event;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

public:
    MiningTruck(int idx);

    void mine();
    void travel_to_unload();
    void queue_to_unload();
    void unload();
    void travel_to_mine();

    void generate_mining_time();

    int get_id() const;

    std::chrono::minutes get_unload_duration() const;
    std::chrono::minutes get_mining_time() const;

    State get_state() const;

    void transition_state(State new_state);
    void update_time_of_unload(Infra::SH3M_SimStepClock::time_point time_of_unload);
    void update_next_event_time();

    Infra::SH3M_SimStepClock::time_point get_time_of_next_event() const;

    void execute_event();
    void set_state(State new_state); // Added method to set the state
};

} // namespace SimH3Mining

#endif // MINING_TRUCK_HPP

