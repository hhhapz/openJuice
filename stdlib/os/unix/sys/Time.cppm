/**
 * @file Time.cppm
 * @brief Module file for Unix time and date operations.
 *
 * This file contains the implementation of the Unix time and date operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/time.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Time;
#else
export module stdlib.os.unix.sys.Time;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using TimeZone = ::timezone;

    using ::gettimeofday;
    using ::settimeofday;
    using ::adjtime;

    using ITimerVal = ::itimerval;

    using ::getitimer;
    using ::setitimer;
    using ::utimes;
    using ::lutimes;
    using ::futimes;
    using ::futimesat;
    #endif
}
