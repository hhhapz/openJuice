/**
 * @file Variant.cppm
 * @brief Module file for importing the Variant class from the standard library.
 * 
 * This file exports the Variant class operations in the standard library.
 */

module;

#include <variant>

#ifdef NO_RESERVED_STD
export module std.core.Variant;
#else
export module stdlib.core.Variant;
#endif

/**
 * @namespace stdlib
 * @brief Wrapper namespace for the standard library.
 */
export namespace stdlib {
    template<typename... Types>
    using Variant = std::variant<Types...>;

    using Monostate = std::monostate;

    template<typename V>
    using VariantSize = std::variant_size<V>;

    template<std::size_t I, typename V>
    using VariantAlternative = std::variant_alternative<I, V>;

    template<std::size_t I, typename T>
    using VariantAlternative_t = std::variant_alternative_t<I, T>;

    using BadVariantAccessException = std::bad_variant_access;

    using std::hash;

    inline constexpr std::size_t VariantNPos = std::variant_npos;

    using std::visit;
    using std::holds_alternative;
    using std::get;
    using std::get_if;
    using std::swap;
}