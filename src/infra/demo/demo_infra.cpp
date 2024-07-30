#include "infra.hpp"
#include <cstdio>

int main()
{
    using namespace SimH3Mining;

    logger.log("Demo start");

    // Accessing the single instance of Infra
    if (auto instance1 = Infra::get_instance()) {
        instance1->get().show_message();
        Infra::log_("This is a log message from instance1");
    } else {
        std::fprintf(stderr, "Failed to get Infra instance.\n");
    }

    // Trying to access the instance again
    if (auto instance2 = Infra::get_instance()) {
        instance2->get().show_message();
//        Infra::log("This is a log message from instance2");
    } else {
        std::fprintf(stderr, "Failed to get Infra instance.\n");
    }

    // Both instance1 and instance2 should point to the same instance
    if (auto instance1 = Infra::get_instance(), instance2 = Infra::get_instance();
        instance1 && instance2 && &instance1->get() == &instance2->get()) {
        std::printf("Both instances are the same.\n");
    } else {
        std::fprintf(stderr, "Instances are not the same or instance creation failed.\n");
    }

    // Directly calling the static log method
    Infra::log_("Direct log call from Infra class");

    return 0;
}
