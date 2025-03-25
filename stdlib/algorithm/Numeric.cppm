/**
 * @file Numeric.cppm
 * @brief Module file for standard library numeric operations.
 *
 * This file contains the implementation of the numeric operations in the standard library.
 */

module;

#include <numeric>

#ifdef NO_RESERVED_STD
export module std.algorithm.Numeric;
#else
export module stdlib.algorithm.Numeric;
#endif

/**
 * @namespace stdlib::algorithm
 * @brief Wrapper namespace for standard library algorithm operations.
 */
export namespace stdlib::algorithm {
    using std::iota;
    using std::accumulate;
    using std::reduce;
    using std::transform_reduce;
    using std::inner_product;
    using std::adjacent_difference;
    using std::partial_sum;
    using std::inclusive_scan;
    using std::exclusive_scan;
    using std::transform_inclusive_scan;
    using std::transform_exclusive_scan;
    using std::gcd;
    using std::lcm;
    using std::midpoint;
}
