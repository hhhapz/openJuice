/**
 * @file IPC.cppm
 * @brief Module file for Unix inter-process communication operations.
 *
 * This file contains the implementation of the Unix inter-process communicatoin operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/ipc.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.IPC;
#else
export module stdlib.os.unix.sys.IPC;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::ftok;
    #endif
}
