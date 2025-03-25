/**
 * @file PIDFD.cppm
 * @brief Module file for Unix process function file descriptor operations.
 *
 * This file contains the implementation of the Unix process function file descriptor operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/pidfd.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.PIDFD;
#else
export module stdlib.os.unix.sys.PIDFD;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::pidfd_open;
    using ::pidfd_getfd;
    using ::pidfd_send_signal;
    using ::pidfd_getpid;
    #endif
}
