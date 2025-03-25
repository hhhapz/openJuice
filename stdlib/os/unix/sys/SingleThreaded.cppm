/**
 * @file SingleThreaded.cppm
 * @brief Module file for Unix single-threaded optimisation support.
 *
 * This file contains the implementation of the Unix single-threaded optimisation support from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/single_threaded.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.SingleThreaded;
#else
export module stdlib.os.unix.sys.SingleThreaded;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::__libc_single_threaded;
    #endif
}
