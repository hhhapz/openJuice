/**
 * @file Pair.cppm
 * @brief Module file for standard library pair operations.
 *
 * This file contains the implementation of the pair operations in the standard library.
 */

module;

#include <utility>

#ifdef NO_RESERVED_STD
export module std.collections.Pair;
#else
export module stdlib.collections.Pair;
#endif

/**
 * @namespace stdlib::collections
 * @brief Wrapper namespace for standard library collection operations.
 */
export namespace stdlib::collections {
    template<typename T1, typename T2>
    using Pair = std::pair<T1, T2>;

    using std::swap;
    using std::get;

    template<typename T>
    using TupleSize = std::tuple_size<T>;

    template<std::size_t I, typename T1, typename T2>
    using TupleElement = std::tuple_element<I, Pair<T1, T2>>;

    using std::operator==;
    using std::operator<=>;
}
