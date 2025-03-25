/**
 * @file Set.cppm
 * @brief Module file for standard library set operations.
 *
 * This file contains the implementation of the set operations in the standard library.
 */

module;

#include <set>

#ifdef NO_RESERVED_STD
export module std.collections.Set;
#else
export module stdlib.collections.Set;
#endif

/**
 * @namespace stdlib::collections
 * @brief Wrapper namespace for standard library collection operations.
 */
export namespace stdlib::collections {
    template<typename T>
    using MultiSet = std::multiset<T>;

    template<typename T>
    using Set = std::set<T>;

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

    using std::swap;
}
