/**
 * @file String.cppm
 * @brief Module file for importing the String class from the standard library.
 * 
 * This file exports the String class operations in the standard library.
 */

module;

#include <string>
#include <string_view>

#ifdef NO_RESERVED_STD
export module std.core.String;
#else
export module stdlib.core.String;
#endif

/**
 * @namespace stdlib
 * @brief Wrapper namespace for the standard library.
 */
export namespace stdlib {
    using String = std::string;

    template<typename CharT>
    using CharTraits = std::char_traits<CharT>;

    template<typename CharT>
    using BasicString = std::basic_string<CharT>;

    using U8String = std::u8string;
    using U16String = std::u16string;
    using U32String = std::u32string;
    using WString = std::wstring;

    using std::stoi;
    using std::stol;
    using std::stoll;
    using std::stoul;
    using std::stoull;
    using std::stof;
    using std::stod;
    using std::stold;
    using std::to_string;
    using std::to_wstring;

    using std::operator+;
    using std::operator==;
    using std::operator""s;
    using std::operator<=>;
    using std::erase;
    using std::erase_if;

    using std::begin;
    using std::cbegin;
    using std::end;
    using std::cend;
    using std::rbegin;
    using std::crbegin;
    using std::rend;
    using std::crend;
    using std::size;
    using std::ssize;
    using std::empty;
    using std::data;

    using std::hash;
    using std::swap;

    template<typename T>
    using BasicStringView = std::basic_string_view<T>;

    using StringView = std::string_view;
    using U8StringView = std::u8string_view;
    using U16StringView = std::u16string_view;
    using U32StringView = std::u32string_view;
    using WStringView = std::wstring_view;
}