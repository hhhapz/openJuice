/**
 * @file Ether.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <netinet/ether.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.netinet.Ether;
#else
export module stdlib.os.unix.netinet.Ether;
#endif

/**
 * @namespace stdlib::os::posix::netinet
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::netinet {
    #ifdef __unix__
    using ::ether_ntoa;
    using ::ether_ntoa_r;
    using ::ether_aton;
    using ::ether_aton_r;
    using ::ether_ntohost;
    using ::ether_hostton;
    using ::ether_line;
    #endif
}
