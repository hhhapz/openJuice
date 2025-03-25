/**
 * @file IOS.cppm
 * @brief Module file for standard library base input/output operations.
 *
 * This file contains the implementation of the base input/output operations in the standard library.
 */

module;

#include <ios>

#ifdef NO_RESERVED_STD
export module std.io.IOS;
#else
export module stdlib.io.IOS;
#endif

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library IO operations.
 */
export namespace stdlib::io {
    using IOSBase = std::ios_base;
    using IOS = std::ios;
    using WIOS = std::wios;

    template<typename StateT>
    using FPos = std::fpos<StateT>;

    using IOErrC = std::io_errc;

    template<typename T>
    using IsErrorCodeEnum = std::is_error_code_enum<T>;

    using StreamOff = std::streamoff;
    using StreamSize = std::streamsize;

    using IOSBaseException = std::ios_base::failure;

    using std::iostream_category;
    using std::make_error_code;
    using std::make_error_condition;
    using std::boolalpha;
    using std::noboolalpha;
    using std::showbase;
    using std::noshowbase;
    using std::showpoint;
    using std::noshowpoint;
    using std::showpos;
    using std::noshowpos;
    using std::skipws;
    using std::noskipws;
    using std::uppercase;
    using std::nouppercase;
    using std::unitbuf;
    using std::nounitbuf;
    using std::internal;
    using std::left;
    using std::right;
    using std::dec;
    using std::hex;
    using std::oct;
    using std::fixed;
    using std::scientific;
    using std::hexfloat;
    using std::defaultfloat;
}
