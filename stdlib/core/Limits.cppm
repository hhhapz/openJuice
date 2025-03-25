/**
 * @file Compare.cppm
 * @brief Module file for standard library limit operations.
 *
 * This file contains the implementation of the limit operations in the standard library.
 */

module;

#include <limits>

#ifdef NO_RESERVED_STD
export module std.core.Limits;
#else
export module stdlib.core.Limits;
#endif

/**
 * @namespace stdlib::limits
 * @brief Wrapper namespace for standard library limit operations.
 */
export namespace stdlib::limits {
    template<typename T>
    using NumericLimits = std::numeric_limits<T>;

    using FloatRoundStyle = std::float_round_style;
    using FloatDenormStyle = std::float_denorm_style;
}
