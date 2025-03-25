/**
 * @file Net.cppm
 * @brief Module file for Unix networking operations.
 *
 * This file contains the implementation of the Unix networking operations from the POSIX libraries.
 */

#ifdef NO_RESERVED_STD
export module std.os.unix.net;
#else
export module stdlib.os.unix.net;
#endif

#ifdef NO_RESERVED_STD
export import std.os.unix.net.Ethernet;
export import std.os.unix.net.If;
export import std.os.unix.net.IfARP;
export import std.os.unix.net.IfPacket;
export import std.os.unix.net.IfPPP;
export import std.os.unix.net.IfShaper;
export import std.os.unix.net.PPPDefs;
export import std.os.unix.net.Route;
#else
export import stdlib.os.unix.net.Ethernet;
export import stdlib.os.unix.net.If;
export import stdlib.os.unix.net.IfARP;
export import stdlib.os.unix.net.IfPacket;
export import stdlib.os.unix.net.IfPPP;
export import stdlib.os.unix.net.IfShaper;
export import stdlib.os.unix.net.PPPDefs;
export import stdlib.os.unix.net.Route;
#endif
