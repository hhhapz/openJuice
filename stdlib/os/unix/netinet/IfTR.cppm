/**
 * @file IfTR.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <netinet/if_tr.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.netinet.IfTR;
#else
export module stdlib.os.unix.netinet.IfTR;
#endif

/**
 * @namespace stdlib::os::posix::netinet
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::netinet {
    #ifdef __unix__
    using TRHHdr = ::trh_hdr;
    using TRLLC = ::trllc;
    using TRStatistics = ::tr_statistics;
    using TRNHdr = ::trn_hdr;
    #endif
}
