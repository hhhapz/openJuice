/**
 * @file IfEther.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <netinet/if_ether.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.netinet.IfEther;
#else
export module stdlib.os.unix.netinet.IfEther;
#endif

/**
 * @namespace stdlib::os::posix::netinet
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::netinet {
    #ifdef __unix__
    using EtherARP = ::ether_arp;
    #endif
}
