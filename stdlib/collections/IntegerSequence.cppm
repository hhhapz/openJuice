/**
 * @file IntegerSequence.cppm
 * @brief Module file for standard library integer sequence operations.
 *
 * This file contains the implementation of the integer sequence operations in the standard library.
 */

module;

#include <utility>

#ifdef NO_RESERVED_STD
export module std.collections.IntegerSequence;
#else
export module stdlib.collections.IntegerSequence;
#endif

/**
 * @namespace stdlib::collections
 * @brief Wrapper namespace for standard library collection operations.
 */
export namespace stdlib::collections {
    template<typename T, T... Elements>
    using IntegerSequence = std::integer_sequence<T>;

    using std::begin;
    using std::end;

    using std::swap;
}
