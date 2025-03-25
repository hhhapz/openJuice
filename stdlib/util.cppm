/**
 * @file sys.cppm
 * @brief Module file for standard library utility operations.
 *
 * This file contains the imports for the utility operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.util;
#else
export module stdlib.util;
#endif

#ifdef NO_RESERVED_STD
export import std.util.StackTrace;
export import std.util.TypeIndex;
export import std.util.TypeInfo;
export import std.util.Utility;
#else
export import stdlib.util.StackTrace;
export import stdlib.util.TypeIndex;
export import stdlib.util.TypeInfo;
export import stdlib.util.Utility;
#endif

export using namespace stdlib;
