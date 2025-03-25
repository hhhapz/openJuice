/**
 * @file Memory.cppm
 * @brief Module file for standard library memory ranges operations.
 *
 * This file contains the implementation of the memory ranges operations in the standard library.
 */

module;

#include <memory>

#ifdef NO_RESERVED_STD
export module std.ranges.Memory;
#else
export module stdlib.ranges.Memory;
#endif

/**
 * @namespace stdlib::ranges
 * @brief Wrapper namespace for standard library ranges operations.
 */
export namespace stdlib::ranges {
    using std::ranges::uninitialized_copy;
    using std::ranges::uninitialized_copy_n;
    using std::ranges::uninitialized_fill;
    using std::ranges::uninitialized_fill_n;
    using std::ranges::uninitialized_move;
    using std::ranges::uninitialized_move_n;
    using std::ranges::uninitialized_default_construct;
    using std::ranges::uninitialized_default_construct_n;
    using std::ranges::uninitialized_value_construct;
    using std::ranges::uninitialized_value_construct_n;
    using std::ranges::destroy;
    using std::ranges::destroy_n;
    using std::ranges::destroy_at;
    using std::ranges::construct_at;
}
