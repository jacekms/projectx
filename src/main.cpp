#include "simulation.hpp"

#include <chrono>
#include <cstdlib> // for std::atoi
#include <cstring> // for std::strlen

bool is_convertible_to_int(const char* str) {
    if (str == nullptr || *str == '\0') return false;
    char* endptr;
    std::strtol(str, &endptr, 10);
    return *endptr == '\0';
}

int main(int argc, char* argv[])
{
    printf("Usage: %s [num_mining_trucks] [num_simulation_time] "
           "[num_simulation_time_minutes]\n", argv[0]);

    int num_mining_trucks = 2;
    int num_unload_stations = 1;
    std::chrono::minutes simulation_time(7*60); // simulate for minutes

    if (argc < 2) {
        printf("Using default values: %d %d %ld\n",
               num_mining_trucks, num_unload_stations, simulation_time.count());
    }

    if (argc > 1) {
        if (is_convertible_to_int(argv[1])) {
            num_mining_trucks = std::atoi(argv[1]);
        } else {
            printf("Arg2 is not int: %s. Using default: %d\n", argv[2],
                    num_mining_trucks);
        }
    }
    printf("num_mining_trucks=%d\n", num_mining_trucks);

    if (argc > 2) {
        if (is_convertible_to_int(argv[2])) {
            num_unload_stations = std::atoi(argv[2]);
        } else {
            printf("Arg2 is not int: %s. Using default: %d\n", argv[2],
                    num_unload_stations);
        }
    }
    printf("num_unload_stations=%d\n", num_unload_stations);

    if (argc > 3) {
        if (is_convertible_to_int(argv[3])) {
            simulation_time = std::chrono::minutes(std::atoi(argv[3]));
        } else {
            printf("Arg2 is not int: %s. Using default\n", argv[2]);
        }
    }
    printf("num_simulation_time=%ld minutes\n", simulation_time.count());


    SimH3Mining::Simulation simulation(num_mining_trucks,
                                       num_unload_stations,
                                       simulation_time);
    simulation.run();

    return 0;
}

