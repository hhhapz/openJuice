/**
 * @file Optional.cppm
 * @brief Module file for importing the Optional class from the standard library.
 * 
 * This file exports the Optional class operations in the standard library.
 */

module;

#include <optional>

#ifdef NO_RESERVED_STD
export module std.core.Optional;
#else
export module stdlib.core.Optional;
#endif

/**
 * @namespace stdlib
 * @brief Wrapper namespace for the standard library.
 */
export namespace stdlib {
    template<typename T>
    using Optional = std::optional<T>;

    using Nullopt_t = std::nullopt_t;

    using BadOptionalAccessException = std::bad_optional_access;

    using std::hash;
    using std::swap;

    using std::make_optional;
}