/**
 * @file UnorderedMap.cppm
 * @brief Module file for standard library unordered map operations.
 *
 * This file contains the implementation of the unordered map operations in the standard library.
 */

module;

#include <unordered_map>

#ifdef NO_RESERVED_STD
export module std.collections.UnorderedMap;
#else
export module stdlib.collections.UnorderedMap;
#endif

/**
 * @namespace stdlib::collections
 * @brief Wrapper namespace for standard library collection operations.
 */
export namespace stdlib::collections {
    template<typename K, typename V>
    using UnorderedMap = std::unordered_map<K, V>;

    template<typename K, typename V>
    using UnorderedMultiMap = std::unordered_multimap<K, V>;

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
