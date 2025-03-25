/**
 * @file CStdLib.cppm
 * @brief Module file for standard library C-style algorithm operations.
 *
 * This file contains the implementation of the C-style algorithm operations in the standard library.
 */

module;

#include <cstdlib>

#ifdef NO_RESERVED_STD
export module std.algorithm.CStdLib;
#else
export module stdlib.algorithm.CStdLib;
#endif

/**
 * @namespace stdlib::algorithm
 * @brief Wrapper namespace for standard library algorithm operations.
 */
export namespace stdlib::algorithm {
    using std::qsort;
    using std::bsearch;
}
