/**
 * @file algorithm.cppm
 * @brief Module file for standard library algorithm operations.
 *
 * This file contains the imports for the algorithm operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.algorithm;
#else
export module stdlib.algorithm;
#endif

#ifdef NO_RESERVED_STD
export import std.algorithm.Algorithm;
export import std.algorithm.CStdLib;
export import std.algorithm.Numeric;
#else
export import stdlib.algorithm.Algorithm;
export import stdlib.algorithm.CStdLib;
export import stdlib.algorithm.Numeric;
#endif

export using namespace stdlib;
