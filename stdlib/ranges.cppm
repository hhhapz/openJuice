/**
 * @file ranges.cppm
 * @brief Module file for standard library ranges operations.
 *
 * This file contains the imports for the ranges operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.ranges;
#else
export module stdlib.ranges;
#endif

#ifdef NO_RESERVED_STD
export import std.ranges.Algorithm;
export import std.ranges.Functional;
export import std.ranges.Generator;
export import std.ranges.Iterator;
export import std.ranges.Memory;
export import std.ranges.Ranges;
#else
export import stdlib.ranges.Algorithm;
export import stdlib.ranges.Functional;
export import stdlib.ranges.Generator;
export import stdlib.ranges.Iterator;
export import stdlib.ranges.Memory;
export import stdlib.ranges.Ranges;
#endif

export using namespace stdlib;
