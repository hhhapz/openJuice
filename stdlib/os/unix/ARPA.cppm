/**
 * @file ARPA.cppm
 * @brief Module file for Unix ARPA operations.
 *
 * This file contains the implementation of the Unix ARPA operations from the POSIX libraries.
 */

#ifdef NO_RESERVED_STD
export module std.os.unix.arpa;
#else
export module stdlib.os.unix.arpa;
#endif

#ifdef NO_RESERVED_STD
export import std.os.unix.arpa.FTP;
export import std.os.unix.arpa.INet;
export import std.os.unix.arpa.NameSer;
export import std.os.unix.arpa.TelNet;
export import std.os.unix.arpa.TFTP;
#else
export import stdlib.os.unix.arpa.FTP;
export import stdlib.os.unix.arpa.INet;
export import stdlib.os.unix.arpa.NameSer;
export import stdlib.os.unix.arpa.TelNet;
export import stdlib.os.unix.arpa.TFTP;
#endif
