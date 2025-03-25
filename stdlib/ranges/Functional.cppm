/**
 * @file Functional.cppm
 * @brief Module file for standard library functional ranges operations.
 *
 * This file contains the implementation of the functional ranges operations in the standard library.
 */

module;

#include <functional>

#ifdef NO_RESERVED_STD
export module std.ranges.Functional;
#else
export module stdlib.ranges.Functional;
#endif

/**
 * @namespace stdlib::ranges
 * @brief Wrapper namespace for standard library ranges operations.
 */
export namespace stdlib::ranges {
    using std::ranges::equal_to;
    using std::ranges::not_equal_to;
    using std::ranges::greater;
    using std::ranges::less;
    using std::ranges::greater_equal;
    using std::ranges::less_equal;
}
