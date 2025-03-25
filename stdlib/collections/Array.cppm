/**
 * @file Array.cppm
 * @brief Module file for standard library array operations.
 *
 * This file contains the implementation of the array operations in the standard library.
 */

module;

#include <array>

#ifdef NO_RESERVED_STD
export module std.collections.Array;
#else
export module stdlib.collections.Array;
#endif

/**
 * @namespace stdlib::collections
 * @brief Wrapper namespace for standard library collection operations.
 */
export namespace stdlib::collections {
    template<typename T, std::size_t N>
    using Array = std::array<T, N>;

    using std::operator==;
    using std::operator<=>;
    using std::to_array;
    using std::get;
    
    using std::begin;
    using std::cbegin;
    using std::end;
    using std::cend;
    using std::rbegin;
    using std::crbegin;
    using std::rend;
    using std::crend;
    using std::size;
    using std::ssize;
    using std::empty;
    using std::data;

    using std::swap;
}
