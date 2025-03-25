/**
 * @file UnorderedSet.cppm
 * @brief Module file for standard library unordered set operations.
 *
 * This file contains the implementation of the unordered set operations in the standard library.
 */

module;

#include <unordered_set>

#ifdef NO_RESERVED_STD
export module std.collections.UnorderedSet;
#else
export module stdlib.collections.UnorderedSet;
#endif

/**
 * @namespace stdlib::collections
 * @brief Wrapper namespace for standard library collection operations.
 */
export namespace stdlib::collections {
    template<typename T>
    using UnorderedMultiSet = std::unordered_multiset<T>;

    template<typename T>
    using UnorderedSet = std::unordered_set<T>;

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
