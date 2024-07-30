#include "logger.hpp"
#include <chrono>

int main() {
    using namespace SimH3Mining;

    // Create a logger instance with default timestamp units (microseconds)
    Logger<> logger;

    // Log a simple message
    logger.log("This is a simple log message.\n");

    // Log a formatted message
    int errorCode = 404;
    logger.log("An error occurred: %d\n", errorCode);

    // Change log file
    logger.set_log_file("app.log");
    logger.log("Logging to a new file now.\n");

    // Create a logger instance with custom timestamp units (milliseconds)
    Logger<std::chrono::milliseconds> logger_ms;
    logger_ms.log("This is a log message with milliseconds timestamp.\n");

    // Create a logger instance with a second clock for additional timestamp (using system_clock for illustration)
    Logger<std::chrono::seconds, std::chrono::system_clock> logger_with_second_clock;
    logger_with_second_clock.log("This log message includes an additional timestamp from the system clock.\n");

    Logger<std::chrono::seconds, std::chrono::system_clock> logger_with_second_clock1("tmp.txt");
    logger_with_second_clock1.log("This log message includes an additional timestamp from the system clock.\n");

    return 0;
}
