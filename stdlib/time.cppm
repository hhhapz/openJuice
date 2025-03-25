/**
 * @file time.cppm
 * @brief Module file for standard library time operations.
 *
 * This file contains the imports for the time operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.time;
#else
export module stdlib.time;
#endif

#ifdef NO_RESERVED_STD
export import std.time.Chrono;
export import std.time.CTime;
#else
export import stdlib.time.Chrono;
export import stdlib.time.CTime;
#endif

export using namespace stdlib;
