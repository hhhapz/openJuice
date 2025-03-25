/**
 * @file Bit.cppm
 * @brief Module file for standard library bit manipulation operations.
 *
 * This file contains the implementation of the bit manipulation operations in the standard library.
 */

module;

#include <bit>

#ifdef NO_RESERVED_STD
export module std.math.Bit;
#else
export module stdlib.math.Bit;
#endif
 
/**
 * @namespace stdlib::math
 * @brief Wrapper namespace for standard library mathematical operations.
 */
export namespace stdlib::math {
    using Endian = std::endian;

    using std::bit_cast;
    using std::byteswap;
    using std::has_single_bit;
    using std::bit_ceil;
    using std::bit_floor;
    using std::bit_width;
    using std::rotl;
    using std::rotr;
    using std::countl_zero;
    using std::countl_one;
    using std::countr_zero;
    using std::countr_one;
    using std::popcount;
}
 