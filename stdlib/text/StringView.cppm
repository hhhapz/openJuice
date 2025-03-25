/**
 * @file StringView.cppm
 * @brief Module file for standard library string view operations.
 *
 * This file contains the implementation of the string view operations in the standard library.
 */

module;

#include <string_view>

#ifdef NO_RESERVED_STD
export module std.text.StringView;
#else
export module stdlib.text.StringView;
#endif

/**
 * @namespace stdlib::string
 * @brief Wrapper namespace for standard library string view operations.
 */
export namespace stdlib::string {
    template<typename T>
    using BasicStringView = std::basic_string_view<T>;

    using StringView = std::string_view;
    using U8StringView = std::u8string_view;
    using U16StringView = std::u16string_view;
    using U32StringView = std::u32string_view;
    using WStringView = std::wstring_view;
}
