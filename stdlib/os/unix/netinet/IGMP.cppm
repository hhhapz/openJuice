/**
 * @file IGMP.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <netinet/igmp.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.netinet.IGMP;
#else
export module stdlib.os.unix.netinet.IGMP;
#endif

/**
 * @namespace stdlib::os::posix::netinet
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::netinet {
    #ifdef __unix__
    using IGMP = ::igmp;
    #endif
}
