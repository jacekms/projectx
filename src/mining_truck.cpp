#include "mining_truck.hpp"

namespace SimH3Mining {


MiningTruck::MiningTruck(int idx) :
    id(idx),
    current_state(State::Mining),

    mining_time(0),
    travel_time(MiningTruckCfg::TRAVEL_TIME),
    wait_in_queue_time(0),
    unload_time(MiningTruckCfg::UNLOAD_TIME),

    time_of_finished_unload(),
    time_to_next_event(0),
    time_of_next_event(),

    generator(std::random_device{}()),
    distribution(MiningTruckCfg::MINING_TIME_DISTRIBUTION_MIN,
                 MiningTruckCfg::MINING_TIME_DISTRIBUTION_MAX)
{
    generate_mining_time(); // First random mining time
    this->update_next_event_time();
}

void MiningTruck::mine() {
    this->add_mining_time(this->mining_time);

    logger.log("Truck%d mined for %2.1lf hours.\n", this->id,
        static_cast<double>(this->mining_time.count()) / 60.0); // to hours

    this->transition_state(State::TravelingToUnload);
}

void MiningTruck::travel_to_unload() {
    this->add_travel_time(std::chrono::minutes(MiningTruckCfg::TRAVEL_TIME));
    logger.log("Truck%d traveling to unload station.\n", this->id);
    this->transition_state(State::WaitingInQueue);
}

void MiningTruck::queue_to_unload() {
    logger.log("Truck%d waiting in queue to unload.\n", this->id);
    this->transition_state(State::Unloading);
}

void MiningTruck::unload() {
    add_wait_time_in_unload_queues(this->unload_time);
    logger.log("Truck%d waiting in queue and unloading for %ld.\n", this->id,
               this->unload_time.count());
    this->transition_state(State::TravelingToMine);
}

void MiningTruck::travel_to_mine() {
    this->add_travel_time(std::chrono::minutes(MiningTruckCfg::TRAVEL_TIME));
    this->add_operation_cycle();
    logger.log("Truck%d traveling to mining site.\n", this->id);
    this->transition_state(State::Mining);
}

void MiningTruck::generate_mining_time() {
    // Random mining time between 1 to 5 hours
    this->mining_time = std::chrono::minutes(this->distribution(this->generator));
}

int MiningTruck::get_id() const {
    return this->id;
}

std::chrono::minutes MiningTruck::get_unload_duration() const {
    return this->unload_time;
}

std::chrono::minutes MiningTruck::get_mining_time() const {
    return this->mining_time;
}

MiningTruck::State MiningTruck::get_state() const {
    return this->current_state;
}

void MiningTruck::transition_state(State new_state)
{
    logger.log("Truck%d state [%s] transition to [%s]\n", this->id,
                get_state_name(this->current_state), get_state_name(new_state));

    this->current_state = new_state;
    this->update_next_event_time();
}

void MiningTruck::update_time_of_unload(Infra::SH3M_SimStepClock::time_point time_of_unload)
{
    auto time_now = Infra::SH3M_SimStepClock::now();
    unload_time = time_of_unload - time_now;
    this->time_of_finished_unload = time_of_unload;
}

void MiningTruck::update_next_event_time()
{
    auto time_now = Infra::SH3M_SimStepClock::now();

    switch (this->current_state)
    {
        case State::Mining:
            generate_mining_time();
            this->time_of_next_event = time_now + this->mining_time;
            this->time_to_next_event = this->mining_time;
        break;
        case State::TravelingToUnload:
            this->time_of_next_event = time_now + this->travel_time;
            this->time_to_next_event = this->travel_time;
        break;
        case State::WaitingInQueue:
            this->time_of_next_event = time_now + this->wait_in_queue_time;
            this->time_to_next_event = this->wait_in_queue_time;
        break;
        case State::Unloading:

            this->time_of_next_event = this->time_of_finished_unload;
            this->time_to_next_event = this->unload_time;

        break;
        case State::TravelingToMine:
            this->time_of_next_event = time_now + this->travel_time;
            this->time_to_next_event = this->travel_time;
        break;
    }
    logger.log("Truck%d [%s] till time=%ld (for %ld)\n", this->id,
               get_state_name(this->current_state),
               this->time_of_next_event, this->time_to_next_event);
}

Infra::SH3M_SimStepClock::time_point MiningTruck::get_time_of_next_event() const {
    return this->time_of_next_event;
}

void MiningTruck::execute_event() {
    switch (this->current_state) {
        case State::Mining:
            this->mine();
        break;
        case State::TravelingToUnload:
            this->travel_to_unload();
        break;
        case State::WaitingInQueue:
            this->queue_to_unload();
        break;
        case State::Unloading:
            this->unload();
        break;
        case State::TravelingToMine:
            this->travel_to_mine();
        break;
    }
}

void MiningTruck::set_state(State new_state) {
    this->current_state = new_state;
}

} // namespace SimH3Mining
