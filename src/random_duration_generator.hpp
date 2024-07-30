#ifndef RANDOM_DURATION_GENERATOR_HPP
#define RANDOM_DURATION_GENERATOR_HPP

#include <random>
#include <chrono>

namespace SimH3Mining {

class RandomDurationGenerator {
private:
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

public:
    RandomDurationGenerator() : distribution(1, 5) {
        std::random_device rd;
        generator.seed(rd());
    }

    std::chrono::minutes generate() {
        return std::chrono::minutes(distribution(generator) * 60);
    }
};

} // namespace SimH3Mining

#endif // RANDOM_DURATION_GENERATOR_HPP
