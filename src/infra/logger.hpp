
#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>
#include <cstdarg>
#include <chrono>
#include <array>
#include <cinttypes> // For PRIu64

namespace SimH3Mining {

template <typename TimeStampUnit = std::chrono::microseconds,
          typename SecondTimeStampClock = void,
          typename SecondTimeStampUnit = std::chrono::microseconds>
class Logger {
public:

    static constexpr int MAX_MSG_LEN = 1024;

    Logger(const char* filename) : file_(stdout) {
        set_log_file(filename);
    }

    Logger() : file_(stdout) {
        this->log("Log started. Output to stdout\n");
        log_timestamp_unit();
    }

    bool set_log_file(const char* filename)
    {
        if (filename == nullptr) {
            this->log("filename is nullptr\n");
            return false;
        }
        ///TODO Add date and time to the filename
        FILE* new_file = std::fopen(filename, "w");
        if (new_file == nullptr) {
            this->log("Unable to open log file=%s. Continuing to use stdout.\n", filename);
            return false;
        }

        if (file_ != stdout) {
            std::fclose(file_);
        }
        file_ = new_file;
        this->log("Log started. Output to file='%s'\n", filename);
        log_timestamp_unit();
        return true;
    }

    void log_timestamp_unit()
    {
        const char* unit;
        if constexpr (std::is_same_v<TimeStampUnit, std::chrono::seconds>) {
            unit = "s";
        } else if constexpr (std::is_same_v<TimeStampUnit, std::chrono::milliseconds>) {
            unit = "ms";
        } else if constexpr (std::is_same_v<TimeStampUnit, std::chrono::microseconds>) {
            unit = "us";
        } else if constexpr (std::is_same_v<TimeStampUnit, std::chrono::nanoseconds>) {
            unit = "ns";
        } else {
            unit = "Unknown";
        }
        this->log("Timestamp unit [%s]\n", unit);
    }

    void log_buf(const char* message) const
    {
        auto now = std::chrono::steady_clock::now();
        int64_t time_since_epoch = std::chrono::duration_cast<TimeStampUnit>
                (now.time_since_epoch()).count();

        if constexpr (!std::is_same_v<SecondTimeStampClock, void>) {
            auto second_now = SecondTimeStampClock::now();
            int64_t second_time_since_epoch = std::chrono::duration_cast
                    <SecondTimeStampUnit>(second_now.time_since_epoch()).count();
            std::fprintf(file_, "%" PRIu64 ", %" PRIu64 ", %s",
                         time_since_epoch, second_time_since_epoch, message);
        } else {
            std::fprintf(file_, "%" PRIu64 ", %s", time_since_epoch, message);
        }
    }

    void log(const char* format, ...) const {
          va_list args;
          va_start(args, format);
          // Format the log message using the private buffer
          std::vsnprintf(buffer_.data(), buffer_.size(), format, args);
          log_buf(buffer_.data());
          va_end(args);
      }

    ~Logger() {
        if (file_ != stdout) {
            std::fclose(file_);
        }
    }

private:
    FILE* file_;
    mutable std::array<char, MAX_MSG_LEN> buffer_; // Buffer for log messages
};

} // namespace SimH3Mining

#endif // LOGGER_H


