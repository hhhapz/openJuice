/**
 * @file Iterator.cppm
 * @brief Module file for standard library iterator operations.
 *
 * This file contains the implementation of the iterator operations in the standard library.
 */

module;

#include <iterator>

#ifdef NO_RESERVED_STD
export module std.ranges.Iterator;
#else
export module stdlib.ranges.Iterator;
#endif

/**
 * @namespace stdlib::iterator
 * @brief Wrapper namespace for standard library iterator operations.
 */
export namespace stdlib::iterator {
    template<typename T>
    using IndirectResult_t = std::indirect_result_t<T>;

    template<typename Iter, typename Proj>
    using Projected = std::projected<Iter, Proj>;
}

/**
 * @namespace stdlib::ranges
 * @brief Wrapper namespace for standard library ranges operations.
 */
export namespace stdlib::ranges {
    using std::ranges::advance;
    using std::ranges::distance;
    using std::ranges::next;
    using std::ranges::prev;
}