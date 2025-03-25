/**
 * @file Generator.cppm
 * @brief Module file for standard library generator operations.
 *
 * This file contains the implementation of the generator operations in the standard library.
 */

module;

#include <generator>

#ifdef NO_RESERVED_STD
export module std.ranges.Generator;
#else
export module stdlib.ranges.Generator;
#endif

/**
 * @namespace stdlib::ranges
 * @brief Wrapper namespace for standard library ranges operations.
 */
export namespace stdlib::ranges {
    template<typename Ref>
    using Generator = std::generator<Ref>;
}
