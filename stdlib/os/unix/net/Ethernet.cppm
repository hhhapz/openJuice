/**
 * @file Ethernet.cppm
 * @brief Module file for Unix local network interfacing operations.
 *
 * This file contains the implementation of the Unix local networking interfacing operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <net/ethernet.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.net.Ethernet;
#else
export module stdlib.os.unix.net.Ethernet;
#endif

/**
 * @namespace stdlib::os::posix::net
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::net {
    #ifdef __unix__
    using EtherAddr = ::ether_addr;
    using EtherHeader = ::ether_header;
    #endif
}
