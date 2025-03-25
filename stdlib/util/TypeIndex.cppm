/**
 * @file CStdLib.cppm
 * @brief Module file for standard library type index operations.
 *
 * This file contains the implementation of the type index operations in the standard library.
 */

module;

#include <typeindex>

#ifdef NO_RESERVED_STD
export module std.util.TypeIndex;
#else
export module stdlib.util.TypeIndex;
#endif

/**
 * @namespace stdlib::util
 * @brief Wrapper namespace for standard library utility operations.
 */
export namespace stdlib::util {
    using TypeIndex = std::type_index;

    using std::hash;
}
