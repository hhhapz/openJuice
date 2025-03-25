/**
 * @file SStream.cppm
 * @brief Module file for standard library string stream operations.
 *
 * This file contains the implementation of the string stream operations in the standard library.
 */

module;

#include <sstream>

#ifdef NO_RESERVED_STD
export module std.io.SStream;
#else
export module stdlib.io.SStream;
#endif

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library input/output operations.
 */
export namespace stdlib::io {
    template<typename CharT>
    using BasicStringBuf = std::basic_stringbuf<CharT>;

    template<typename CharT>
    using BasicStringStream = std::basic_stringstream<CharT>;

    template<typename CharT>
    using BasicIStringStream = std::basic_istringstream<CharT>;

    template<typename CharT>
    using BasicOStringStream = std::basic_ostringstream<CharT>;

    using StringBuf = std::stringbuf;
    using WStringBuf = std::wstringbuf;
    using StringStream = std::stringstream;
    using WStringStream = std::wstringstream;
    using IStringStream = std::istringstream;
    using WIStringStream = std::wistringstream;
    using OStringStream = std::ostringstream;
    using WOStringStream = std::wostringstream;

    using std::swap;
}
