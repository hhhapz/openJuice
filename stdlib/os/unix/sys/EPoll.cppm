/**
 * @file EPoll.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/epoll.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.EPoll;
#else
export module stdlib.os.unix.sys.EPoll;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::EPOLL_EVENTS;

    using EPollData = ::epoll_data;
    using EPollEvent = ::epoll_event;
    using EPollParams = ::epoll_params;

    using ::epoll_create;
    using ::epoll_create1;
    using ::epoll_ctl;
    using ::epoll_wait;
    using ::epoll_pwait;
    using ::epoll_pwait2;
    #endif
}
