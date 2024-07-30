#include "logger.hpp"
#include <gtest/gtest.h>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>

// Helper function to read a file into a string
std::string readFile(const char* filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

namespace {

TEST(LoggerTest, LogToStdout) {
    SimH3Mining::Logger<> logger;

    // Redirect stdout to a file
    const char* temp_stdout = "temp_stdout.log";
    freopen(temp_stdout, "w", stdout);

    logger.log("Test log message to stdout.");
    std::string log_content = readFile(temp_stdout);

    EXPECT_NE(log_content.find("Test log message to stdout."), std::string::npos);

    // Restore stdout
    freopen("/dev/tty", "w", stdout);
    std::remove(temp_stdout);
}

TEST(LoggerTest, LogToFile) {
    SimH3Mining::Logger<> logger;
    const char* log_filename = "test_log_file.log";

    // Set log file
    logger.set_log_file(log_filename);
    logger.log("Test log message to file.");

    std::string log_content = readFile(log_filename);
    EXPECT_NE(log_content.find("Test log message to file."), std::string::npos);

    std::remove(log_filename);
}

TEST(LoggerTest, LogWithTimestampUnits) {
    SimH3Mining::Logger<std::chrono::milliseconds> logger_ms;
    SimH3Mining::Logger<std::chrono::seconds> logger_s;
    SimH3Mining::Logger<std::chrono::nanoseconds> logger_ns;

    // Redirect stdout to a file
    const char* temp_stdout = "temp_stdout.log";
    freopen(temp_stdout, "w", stdout);

    logger_ms.log("Milliseconds timestamp unit.");
    logger_s.log("Seconds timestamp unit.");
    logger_ns.log("Nanoseconds timestamp unit.");

    std::string log_content = readFile(temp_stdout);

    EXPECT_NE(log_content.find("Milliseconds timestamp unit."), std::string::npos);
    EXPECT_NE(log_content.find("Seconds timestamp unit."), std::string::npos);
    EXPECT_NE(log_content.find("Nanoseconds timestamp unit."), std::string::npos);

    // Restore stdout
    freopen("/dev/tty", "w", stdout);
    std::remove(temp_stdout);
}

TEST(LoggerTest, LogWithSecondTimeStampClock) {
    SimH3Mining::Logger<std::chrono::microseconds, std::chrono::system_clock> logger_with_second_clock;

    // Redirect stdout to a file
    const char* temp_stdout = "temp_stdout.log";
    freopen(temp_stdout, "w", stdout);

    logger_with_second_clock.log("Log message with second timestamp clock.");
    std::string log_content = readFile(temp_stdout);

    EXPECT_NE(log_content.find("Log message with second timestamp clock."), std::string::npos);

    // Restore stdout
    freopen("/dev/tty", "w", stdout);
    std::remove(temp_stdout);
}

}  // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


