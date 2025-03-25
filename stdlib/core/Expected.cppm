/**
 * @file Expected.cppm
 * @brief Module file for importing the Expected class from the standard library.
 * 
 * This file exports the Expected class operations in the standard library.
 */

module;

#include <expected>

#ifdef NO_RESERVED_STD
export module std.core.Expected;
#else
export module stdlib.core.Expected;
#endif

/**
 * @namespace stdlib
 * @brief Wrapper namespace for the standard library.
 */
export namespace stdlib {
    template<typename T, typename E>
    using Expected = std::expected<T, E>;

    template<typename E>
    using Unexpected = std::unexpected<E>;

    using Unexpect_t = std::unexpect_t;

    template<typename E>
    using BadExpectedAccessException = std::bad_expected_access<E>;

    using std::swap;
}