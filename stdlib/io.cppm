/**
 * @file io.cppm
 * @brief Module file for standard library input/output operations.
 *
 * This file contains the imports for the input/output operations in the standard library.
 */

module;

#include <string>

#ifdef NO_RESERVED_STD
export module std.io;
#else
export module stdlib.io;
#endif

#ifdef NO_RESERVED_STD
export import std.io.CStdIO;
export import std.io.CWChar;
export import std.io.FStream;
export import std.io.IStream;
export import std.io.IOManip;
export import std.io.IOS;
export import std.io.IOStream;
export import std.io.OStream;
export import std.io.Print;
export import std.io.SpanStream;
export import std.io.SStream;
export import std.io.StreamBuf;
export import std.io.SyncStream;
#else
export import stdlib.io.CStdIO;
export import stdlib.io.CWChar;
export import stdlib.io.FStream;
export import stdlib.io.IStream;
export import stdlib.io.IOManip;
export import stdlib.io.IOS;
export import stdlib.io.IOStream;
export import stdlib.io.OStream;
export import stdlib.io.Print;
export import stdlib.io.SpanStream;
export import stdlib.io.SStream;
export import stdlib.io.StreamBuf;
export import stdlib.io.SyncStream;
#endif

/**
 * @brief Wrapper namespace for standard library input/output operations.
 */
export namespace stdlib::io {
    using std::getline;
}

export using namespace stdlib;
