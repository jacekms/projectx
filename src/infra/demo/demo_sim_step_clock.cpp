#include "sim_step_clock.hpp"

#include <chrono>
#include <cstdio>
#include <ratio>

#include <inttypes.h>


// Helper function to print time points
template<typename Clock, typename PrintUnit>
void print_time(const typename Clock::time_point& tp, const char* unit) {
    using duration_t = std::chrono::duration<typename Clock::rep, typename PrintUnit::period>;
    auto time_as_print_unit = std::chrono::time_point_cast<duration_t>(tp);
    std::printf("SimStepClock time: %" PRIi64 " %s\n", time_as_print_unit.time_since_epoch().count(), unit);
}

void demo_function() {
    using ClockSeconds = SimStepClock<std::chrono::seconds>;
    using ClockMilliseconds = SimStepClock<std::chrono::milliseconds>;
    using ClockMinutes = SimStepClock<std::chrono::minutes>;

    // Working with seconds
    auto start_time_seconds = ClockSeconds::now();
    print_time<ClockSeconds, std::chrono::seconds>(start_time_seconds, "seconds");

    ClockSeconds::advance(std::chrono::seconds(10));
    auto time_after_10s = ClockSeconds::now();
    print_time<ClockSeconds, std::chrono::seconds>(time_after_10s, "seconds");

    ClockSeconds::advance(std::chrono::minutes(5));
    auto time_after_5m = ClockSeconds::now();
    print_time<ClockSeconds, std::chrono::seconds>(time_after_5m, "seconds");

    // Working with milliseconds
    auto start_time_milliseconds = ClockMilliseconds::now();
    print_time<ClockMilliseconds, std::chrono::milliseconds>(start_time_milliseconds, "milliseconds");

    ClockMilliseconds::advance(std::chrono::milliseconds(10000));
    auto time_after_10s_ms = ClockMilliseconds::now();
    print_time<ClockMilliseconds, std::chrono::milliseconds>(time_after_10s_ms, "milliseconds");

    ClockMilliseconds::advance(std::chrono::milliseconds(300000));
    auto time_after_5m_ms = ClockMilliseconds::now();
    print_time<ClockMilliseconds, std::chrono::milliseconds>(time_after_5m_ms, "milliseconds");

    // Print time as minutes
    print_time<ClockMilliseconds, std::chrono::minutes>(time_after_5m_ms, "minutes");

    // Working with minutes and printing as hours
    ClockMinutes::advance(std::chrono::minutes(130));
    auto time_after_130m = ClockMinutes::now();
    print_time<ClockMinutes, std::chrono::hours>(time_after_130m, "hours");
}

int main() {
    demo_function();
    return 0;
}

