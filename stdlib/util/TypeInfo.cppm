/**
 * @file CStdLib.cppm
 * @brief Module file for standard library type information operations.
 *
 * This file contains the implementation of the type information operations in the standard library.
 */

module;

#include <typeinfo>

#ifdef NO_RESERVED_STD
export module std.util.TypeInfo;
#else
export module stdlib.util.TypeInfo;
#endif

/**
 * @namespace stdlib::util
 * @brief Wrapper namespace for standard library utility operations.
 */
export namespace stdlib::util {
    using TypeInfo = std::type_info;

    using BadCastException = std::bad_cast;
    using BadTypeIDException = std::bad_typeid;
}
