/**
 * @file IP.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <netinet/ip.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.netinet.IP;
#else
export module stdlib.os.unix.netinet.IP;
#endif

/**
 * @namespace stdlib::os::posix::netinet
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::netinet {
    #ifdef __unix__
    using TimeStamp = ::timestamp;
    using IPHdr = ::iphdr;
    using IP = ::ip;
    using IPTimeStamp = ::ip_timestamp;
    #endif
}
