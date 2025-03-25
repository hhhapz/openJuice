/**
 * @file CIntTypes.cppm
 * @brief Module file for standard library C-style integer formatting constant operations.
 *
 * This file contains the implementation of the C-style integer formatting constants operations in the standard library.
 */

module;

#include <cinttypes>

#ifdef NO_RESERVED_STD
export module std.fmt.CIntTypes;
#else
export module stdlib.fmt.CIntTypes;
#endif

export import :Constants;

/**
 * @namespace stdlib::fmt
 * @brief Wrapper namespace for standard library format operations.
 */
export namespace stdlib::fmt {
    using IMaxDiv_t = std::imaxdiv_t;

    using std::imaxabs;
    using std::imaxdiv;
    using std::strtoimax;
    using std::strtoumax;
    using std::wcstoimax;
    using std::wcstoumax;
}
