/**
 * @file Vector.cppm
 * @brief Module file for standard library vector operations.
 *
 * This file contains the implementation of the vector operations in the standard library.
 */

module;

#include <vector>

#ifdef NO_RESERVED_STD
export module std.collections.Vector;
#else
export module stdlib.collections.Vector;
#endif

/**
 * @namespace stdlib::collections
 * @brief Wrapper namespace for standard library collection operations.
 */
export namespace stdlib::collections {
    template<typename T>
    using Vector = std::vector<T>;

    using std::erase;
    using std::erase_if;

    using std::operator==;
    using std::operator<=>;

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

    using std::hash;
    using std::swap;
}
