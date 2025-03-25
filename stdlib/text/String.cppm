/**
 * @file String.cppm
 * @brief Module file for standard library string operations.
 *
 * This file contains the implementation of the string operations in the standard library.
 */

module;

#include <string>

#ifdef NO_RESERVED_STD
export module std.text.String;
#else
export module stdlib.text.String;
#endif

/**
 * @namespace stdlib::string
 * @brief Wrapper namespace for standard library string operations.
 */
export namespace stdlib::string {
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
}