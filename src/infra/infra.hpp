#ifndef INFRA_HPP
#define INFRA_HPP

#include "sh3m_assert.hpp"
#include "logger.hpp"
#include "sim_step_clock.hpp"

#include <optional>
#include <memory>
#include <mutex>

namespace SimH3Mining {

class Infra : public Logger<>
{
public:
    using SH3M_SimStepClock = SimStepClock<std::chrono::minutes>;

    //using SH3M_Logger = Logger<std::chrono::seconds, std::chrono::system_clock>;
    using SH3M_Logger = Logger<std::chrono::microseconds,
        SH3M_SimStepClock, std::chrono::minutes>;

    // Delete copy constructor and assignment operator to prevent copying
    Infra(const Infra&) = delete;
    Infra& operator=(const Infra&) = delete;

    ~Infra();

    // Static access to the singleton instance
    static std::optional<std::reference_wrapper<Infra>> get_instance();

private:
    Infra(); // Private constructor prevents instantiation from outside the class

    static void init_singleton(); // Creates the singleton instance
    // Static member variables and inline initialization
    static inline std::unique_ptr<Infra> instance{nullptr}; // Manages the singleton instance
    static inline std::once_flag init_instance_flag; // Flag ensures single instance

};

extern Infra::SH3M_Logger logger; // Declaration of the global logger instance

} // namespace SimH3Mining

#endif // INFRA_HPP
