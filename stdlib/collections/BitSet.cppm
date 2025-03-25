/**
 * @file BitSet.cppm
 * @brief Module file for standard library bitset operations.
 *
 * This file contains the implementation of the bitset operations in the standard library.
 */

module;

#include <bitset>

#ifdef NO_RESERVED_STD
export module std.collections.BitSet;
#else
export module stdlib.collections.BitSet;
#endif

/**
 * @namespace stdlib::collections
 * @brief Wrapper namespace for standard library collection operations.
 */
export namespace stdlib::collections {
    template<std::size_t N>
    using BitSet = std::bitset<N>;

    using std::operator&;
    using std::operator|;
    using std::operator^;
    using std::operator<<;
    using std::operator>>;

    using std::hash;
    using std::swap;
}
