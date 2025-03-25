/**
 * @file UN.cppm
 * @brief Module file for Unix domain socket operations.
 *
 * This file contains the implementation of the Unix domain socket operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/un.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.UN;
#else
export module stdlib.os.unix.sys.UN;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using SockAddrUN = ::sockaddr_un;
    #endif
}
