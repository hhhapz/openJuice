/**
 * @file Any.cppm
 * @brief Module file for importing the Any class from the standard library.
 * 
 * This file exports the Any class operations in the standard library.
 */

module;

#include <any>

#ifdef NO_RESERVED_STD
export module std.core.Any;
#else
export module stdlib.core.Any;
#endif

/**
 * @namespace stdlib
 * @brief Wrapper namespace for the standard library.
 */
export namespace stdlib {
    using Any = std::any;

    using BadAnyCastException = std::bad_any_cast;

    using std::make_any;
    using std::any_cast;

    using std::swap;
}