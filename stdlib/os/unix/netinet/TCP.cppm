/**
 * @file TCP.cppm
 * @brief Module file for Unix TCP control operations.
 *
 * This file contains the implementation of the Unix TCP control operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <netinet/tcp.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.netinet.TCP;
#else
export module stdlib.os.unix.netinet.TCP;
#endif

/**
 * @namespace stdlib::os::posix::netinet
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::netinet {
    #ifdef __unix__
    using TCPHdr = ::tcphdr;
    using TCPCAState = ::tcp_ca_state;
    using TCPInfo = ::tcp_info;
    using TCPMD5Sig = ::tcp_md5sig;
    using TCPRepairOpt = ::tcp_repair_opt;
    using TCPCookieTransactions = ::tcp_cookie_transactions;
    using TCPRepairWindow = ::tcp_repair_window;
    using TCPZeroCopyRecieve = ::tcp_zerocopy_receive;
    #endif
}
