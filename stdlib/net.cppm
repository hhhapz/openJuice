/**
 * @file net.cppm
 * @brief Module file for standard library networking operations.
 *
 * This file contains the imports for the networking operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.net;
#else
export module stdlib.net;
#endif

#ifdef NO_RESERVED_STD
export import std.net.Buffer;
export import std.net.Executor;
export import std.net.Internet;
export import std.net.IOContext;
export import std.net.Socket;
export import std.net.Timer;
#else
export import stdlib.net.Buffer;
export import stdlib.net.Executor;
export import stdlib.net.Internet;
export import stdlib.net.IOContext;
export import stdlib.net.Socket;
export import stdlib.net.Timer;
#endif

export using namespace stdlib;
