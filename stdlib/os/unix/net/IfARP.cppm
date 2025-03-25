/**
 * @file IfARP.cppm
 * @brief Module file for Unix local network interfacing operations.
 *
 * This file contains the implementation of the Unix local networking interfacing operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <net/if_arp.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.net.IfARP;
#else
export module stdlib.os.unix.net.IfARP;
#endif

/**
 * @namespace stdlib::os::posix::net
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::net {
    #ifdef __unix__
    using ARPHdr = ::arphdr;
    using ARPReq = ::arpreq;
    using ARPReqOld = ::arpreq_old;
    using ARPDRequest = ::arpd_request;
    #endif
}
