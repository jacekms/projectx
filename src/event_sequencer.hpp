
#ifndef EVENT_SEQUENCER_HPP
#define EVENT_SEQUENCER_HPP

#include <queue>
#include <optional>
#include <chrono>
#include "mining_truck.hpp"

namespace SimH3Mining {

class Event {
public:
    Infra::SH3M_SimStepClock::time_point time;
    MiningTruck* truck;

    Event(Infra::SH3M_SimStepClock::time_point time, MiningTruck* truck);

    bool operator<(const Event& other) const;
    void execute();
};




class EventSequencer {
private:
    std::priority_queue<Event> events;

public:
    void schedule_event(const Event& event);
    std::optional<Event> get_next_event();
    bool has_events() const;
};

} // namespace SimH3Mining


#endif // EVENT_SEQUENCER_HPP
