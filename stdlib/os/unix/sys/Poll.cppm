/**
 * @file Poll.cppm
 * @brief Module file for Unix System V poll interface compatibility operations.
 *
 * This file contains the implementation of the Unix System V poll interface compatibility operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/poll.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Poll;
#else
export module stdlib.os.unix.sys.Poll;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using PollFD = ::pollfd;

    using ::poll;
    using ::ppoll;
    #endif
}
