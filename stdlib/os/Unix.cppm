/**
 * @file Unix.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

#ifdef NO_RESERVED_STD
export module std.os.Unix;
#else
export module stdlib.os.Unix;
#endif

#ifdef NO_RESERVED_STD
export import std.os.unix.AIO;
export import std.os.unix.arpa;
export import std.os.unix.DirEnt;
export import std.os.unix.DLFCn;
export import std.os.unix.FCntl;
export import std.os.unix.FmtMsg;
export import std.os.unix.FnMatch;
export import std.os.unix.FTW;
export import std.os.unix.Glob;
export import std.os.unix.Grp;
export import std.os.unix.IConv;
export import std.os.unix.LangInfo;
export import std.os.unix.LibGen;
export import std.os.unix.Monetary;
export import std.os.unix.MQueue;
export import std.os.unix.NDBM;
export import std.os.unix.net;
export import std.os.unix.NetDB;
export import std.os.unix.netinet;
export import std.os.unix.NLTypes;
export import std.os.unix.PThread;
export import std.os.unix.Pwd;
export import std.os.unix.RegEx;
export import std.os.unix.Sched;
export import std.os.unix.Search;
export import std.os.unix.Semaphore;
export import std.os.unix.Spawn;
export import std.os.unix.Strings;
export import std.os.unix.sys;
export import std.os.unix.TermIOS;
export import std.os.unix.UniStd;
export import std.os.unix.UTime;
export import std.os.unix.UTMPX;
export import std.os.unix.WordExp;
#else
export import stdlib.os.unix.AIO;
export import stdlib.os.unix.arpa;
export import stdlib.os.unix.DirEnt;
export import stdlib.os.unix.DLFCn;
export import stdlib.os.unix.FCntl;
export import stdlib.os.unix.FmtMsg;
export import stdlib.os.unix.FnMatch;
export import stdlib.os.unix.FTW;
export import stdlib.os.unix.Glob;
export import stdlib.os.unix.Grp;
export import stdlib.os.unix.IConv;
export import stdlib.os.unix.LangInfo;
export import stdlib.os.unix.LibGen;
export import stdlib.os.unix.Monetary;
export import stdlib.os.unix.MQueue;
export import stdlib.os.unix.NDBM;
export import stdlib.os.unix.net;
export import stdlib.os.unix.NetDB;
export import stdlib.os.unix.netinet;
export import stdlib.os.unix.NLTypes;
export import stdlib.os.unix.PThread;
export import stdlib.os.unix.Pwd;
export import stdlib.os.unix.RegEx;
export import stdlib.os.unix.Sched;
export import stdlib.os.unix.Search;
export import stdlib.os.unix.Semaphore;
export import stdlib.os.unix.Spawn;
export import stdlib.os.unix.Strings;
export import stdlib.os.unix.sys;
export import stdlib.os.unix.TermIOS;
export import stdlib.os.unix.UniStd;
export import stdlib.os.unix.UTime;
export import stdlib.os.unix.UTMPX;
export import stdlib.os.unix.WordExp;
#endif
