
//#include "event.hpp"
#include "event_sequencer.hpp"

namespace SimH3Mining {

Event::Event(Infra::SH3M_SimStepClock::time_point timex, MiningTruck* truckx)
    : time(timex), truck(truckx) {}

bool Event::operator<(const Event& other) const {
    return time > other.time;  // Reverse for priority_queue to work as min-heap
}

void Event::execute() {
    truck->execute_event();
}

void EventSequencer::schedule_event(const Event& event) {
    events.push(event);
}

std::optional<Event> EventSequencer::get_next_event() {
    if (events.empty()) {
        return std::nullopt;
    }
    Event next_event = events.top();
    events.pop();
    return next_event;
}

bool EventSequencer::has_events() const {
    return !events.empty();
}


} // namespace SimH3Mining
