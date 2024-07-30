#ifndef SIM_STEP_CLOCK_HPP
#define SIM_STEP_CLOCK_HPP

#include <chrono>
#include <ratio>


template<typename Duration = std::chrono::seconds>
class SimStepClock {
public:
    //using rep = std::int64_t;
    using rep = typename Duration::rep;
    using period = typename Duration::period;
    using duration = Duration;
    using time_point = std::chrono::time_point<SimStepClock, duration>;

    static constexpr bool is_steady = false;

    static time_point now() noexcept {
        return current_time;
    }

    static void advance(duration step) noexcept {
        current_time += step;
    }

    static void set_time(SimStepClock::time_point time_p) noexcept {
        current_time = time_p;
    }

private:
    static inline time_point current_time{duration{0}};
};

#endif // SIM_STEP_CLOCK_HPP

