/**
 * @file NetINet.cppm
 * @brief Module file for Unix NetINet operations.
 *
 * This file contains the implementation of the Unix NetINet operations from the POSIX libraries.
 */

#ifdef NO_RESERVED_STD
export module std.os.unix.netinet;
#else
export module stdlib.os.unix.netinet;
#endif

#ifdef NO_RESERVED_STD
export import std.os.unix.netinet.Ether;
export import std.os.unix.netinet.ICMP6;
export import std.os.unix.netinet.IfEther;
export import std.os.unix.netinet.IfFDDI;
export import std.os.unix.netinet.IfTR;
export import std.os.unix.netinet.IGMP;
export import std.os.unix.netinet.In;
export import std.os.unix.netinet.IP;
export import std.os.unix.netinet.IP6;
export import std.os.unix.netinet.IPICMP;
export import std.os.unix.netinet.TCP;
export import std.os.unix.netinet.UDP;
#else
export import stdlib.os.unix.netinet.Ether;
export import stdlib.os.unix.netinet.ICMP6;
export import stdlib.os.unix.netinet.IfEther;
export import stdlib.os.unix.netinet.IfFDDI;
export import stdlib.os.unix.netinet.IfTR;
export import stdlib.os.unix.netinet.IGMP;
export import stdlib.os.unix.netinet.In;
export import stdlib.os.unix.netinet.IP;
export import stdlib.os.unix.netinet.IP6;
export import stdlib.os.unix.netinet.IPICMP;
export import stdlib.os.unix.netinet.TCP;
export import stdlib.os.unix.netinet.UDP;
#endif
