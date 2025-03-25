/**
 * @file String.cppm
 * @brief Module file for importing the byte type from the standard library.
 * 
 * This file exports the byte type in the standard library.
 */

module;

#include <cstddef>

#ifdef NO_RESERVED_STD
export module std.core.CStdDef;
#else
export module stdlib.core.CStdDef;
#endif

/**
 * @namespace stdlib
 * @brief Wrapper namespace for the standard library.
 */
export namespace stdlib {
    using byte = std::byte;
}