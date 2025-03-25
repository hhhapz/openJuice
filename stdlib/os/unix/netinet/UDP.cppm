/**
 * @file UDP.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <netinet/udp.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.netinet.UDP;
#else
export module stdlib.os.unix.netinet.UDP;
#endif

/**
 * @namespace stdlib::os::posix::netinet
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::netinet {
    #ifdef __unix__
    using UDPHdr = ::udphdr;
    #endif
}
