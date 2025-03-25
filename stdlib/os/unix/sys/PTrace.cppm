/**
 * @file PTrace.cppm
 * @brief Module file for Unix ptrace debugger interface operations.
 *
 * This file contains the implementation of the Unix ptrace debugger interface operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/ptrace.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.PTrace;
#else
export module stdlib.os.unix.sys.PTrace;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::ptrace;
    #endif
}
