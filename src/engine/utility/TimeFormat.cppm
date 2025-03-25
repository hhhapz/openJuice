/**
 * @file TimeFormat.cppm
 * @brief Implementation of the TimeFormat namespace.
 *
 * This file contains the implementation of the TimeFormat namespace, which provides utility functions for handling time.
 */

module;

#include <chrono>

export module engine.utility.TimeFormat;

#ifdef NO_RESERVED_STD
import std.core;
import std.io;
import std.time;
#else
import stdlib.core;
import stdlib.io;
import stdlib.time;
#endif

/**
 * @namespace timeformat
 * @brief Namespace for time formatting utility functions.
 */
export namespace timeformat {
    /**
     * @brief Get the current time as a string.
     * @return The current time formatted as a string.
     */
    String getCurrentTimeAsString() {
        time::TimePoint<time::SystemClock::duration> now = time::SystemClock::now();
        time::Time nowTime = time::SystemClock::to_time_t(now);
        time::TM* nowTM = time::fmt::localtime(&nowTime);
        io::OStringStream oss;
        oss << io::put_time(nowTM, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }
}