/**
 * @file Tuple.cppm
 * @brief Module file for standard library tuple operations.
 *
 * This file contains the implementation of the tuple operations in the standard library.
 */

module;

#include <tuple>

#ifdef NO_RESERVED_STD
export module std.collections.Tuple;
#else
export module stdlib.collections.Tuple;
#endif

/**
 * @namespace stdlib::collections
 * @brief Wrapper namespace for standard library collection operations.
 */
export namespace stdlib::collections {
    template<typename... Elements>
    using Tuple = std::tuple<Elements...>;

    template<typename T>
    using TupleSize = std::tuple_size<T>;

    template<std::size_t I, typename T>
    using TupleElement = std::tuple_element<I, T>;

    using std::operator==;
    using std::operator<=>;

    using std::make_tuple;
    using std::tie;
    using std::forward_as_tuple;
    using std::tuple_cat;
    using std::get;
    using std::apply;
    using std::make_from_tuple;

    using std::swap;
}
