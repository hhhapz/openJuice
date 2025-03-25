/**
 * @file os.cppm
 * @brief Module file for standard library operating system operations.
 *
 * This file contains the imports for the operating system operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.os;
#else
export module stdlib.os;
#endif

#ifdef NO_RESERVED_STD
export import std.os.Unix;
export import std.os.Win32;
#else
export import stdlib.os.Unix;
export import stdlib.os.Win32;
#endif

export using namespace stdlib;
