/**
 * @file PSXSysCall.cppm
 * @brief Module file for Unix POSIX syscalls for pthread operations.
 *
 * This file contains the implementation of the Unix POSIX syscalls for pthread operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/psx_syscall.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.PSXSysCall;
#else
export module stdlib.os.unix.sys.PSXSysCall;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::psx_load_syscalls;
    using ::psx_set_sensitivity;
    #endif
}
