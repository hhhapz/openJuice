/**
 * @file sys.cppm
 * @brief Module file for standard library system operations.
 *
 * This file contains the imports for the system operations in the standard library.
 */

module;

#include <utility>

#ifdef NO_RESERVED_STD
export module std.sys;
#else
export module stdlib.sys;
#endif

#ifdef NO_RESERVED_STD
export import std.sys.CSetJmp;
export improt std.sys.CSignal;
export import std.sys.CStdLib;
export import std.sys.SystemError;
#else
export import stdlib.sys.CSetJmp;
export import stdlib.sys.CSignal;
export import stdlib.sys.CStdLib;
export import stdlib.sys.SystemError;
#endif

export namespace stdlib::sys {
    using std::unreachable;
}

export using namespace stdlib;
