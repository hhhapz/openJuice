/**
 * @file CTime.cppm
 * @brief Module file for standard library C-style time operations.
 *
 * This file contains the implementation of the C-style time operations in the standard library.
 */

module;

#include <ctime>

#ifdef NO_RESERVED_STD
export module std.time.CTime;
#else
export module stdlib.time.CTime;
#endif

/**
 * @namespace stdlib::time
 * @brief Wrapper namespace for standard library time operations.
 */
export namespace stdlib::time {
    using TM = std::tm;
    using Time = std::time_t;
    using Clock = std::clock_t;
    
    using std::clock;
    using std::time;
    using std::difftime;

    /**
     * @brief fmt
     * @brief Wrapper namespace for standard library time formatting operations
     */
    namespace fmt {
        using std::timespec_get;
        using std::ctime;
        using std::asctime;
        using std::strftime;
        using std::gmtime;
        using std::localtime;
        using std::mktime;
    }
}
