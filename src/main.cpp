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

///TODO Find a resonable max limits to protect from std::vector malloc issues?
enum MaxValuesCfg : int {
    MAX_VAL_NUM_MINING_TRUCKS   = 1000,
    MAX_VAL_NUM_UNLOAD_STATIONS = 1000
};

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
            printf("Arg1 is not int: %s. Using default: %d\n", argv[1],
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

    if (argc > 3)
    {
        char* end;
        errno = 0;  // Reset errno before the call
        int64_t value = std::strtoll(argv[3], &end, 10);

        // Check for errors
        if (errno == ERANGE) {
            printf("Error: Value out of range for int64_t.\n");
            return 1;
        }
        if (*end != '\0') {
            printf("Error: Invalid characters found in input.\n");
            return 1;
        }
        simulation_time = std::chrono::minutes(value);
    }
    printf("num_simulation_time=%ld minutes\n", simulation_time.count());

    if (num_mining_trucks <= 0 or num_unload_stations <= 0) {
        printf("Not supported: num_mining_trucks == 0 or num_unload_stations == 0\n");
        return 1;
    }

    ///TODO Find a resonable max limits
    if (num_mining_trucks > MAX_VAL_NUM_MINING_TRUCKS or
        num_unload_stations > MAX_VAL_NUM_UNLOAD_STATIONS)
    {
        printf("Not supported: num_mining_trucks > %d or num_unload_stations > %d\n",
               MAX_VAL_NUM_MINING_TRUCKS, MAX_VAL_NUM_UNLOAD_STATIONS);
        return 1;
    }

    if (simulation_time.count() <= 0 && simulation_time.count() >= std::chrono::minutes::max().count())
    {
        printf("Not supported: simulation_time <= 0 or simulation_time >= %ld\n",
             std::chrono::minutes::max().count());
        return 1;
    }


    SimH3Mining::Simulation simulation(num_mining_trucks,
                                       num_unload_stations,
                                       simulation_time);
    simulation.run();

    return 0;
}

