/**
 * @file Map.cppm
 * @brief Module file for standard library map operations.
 *
 * This file contains the implementation of the map operations in the standard library.
 */

module;

#include <map>

#ifdef NO_RESERVED_STD
export module std.collections.Map;
#else
export module stdlib.collections.Map;
#endif

/**
 * @namespace stdlib::collections
 * @brief Wrapper namespace for standard library collection operations.
 */
export namespace stdlib::collections {
    template<typename K, typename V>
    using Map = std::map<K, V>;

    template<typename K, typename V>
    using MultiMap = std::multimap<K, V>;

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
