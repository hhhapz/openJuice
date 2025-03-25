/**
 * @file Ranges.cppm
 * @brief Module file for standard library ranges operations.
 *
 * This file contains the implementation of the ranges operations in the standard library.
 */

module;

#include <ranges>

#ifdef NO_RESERVED_STD
export module std.ranges.Ranges;
#else
export module stdlib.ranges.Ranges;
#endif

/**
 * @namespace stdlib::ranges
 * @brief Wrapper namespace for standard library ranges operations.
 */
export namespace stdlib::ranges {
    using std::ranges::iota_view;
    using std::ranges::views::iota;
}
