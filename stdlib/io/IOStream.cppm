/**
 * @file IOStream.cppm
 * @brief Module file for standard library input/output stream operations.
 *
 * This file contains the implementation of the input/output stream operations in the standard library.
 */

module;

#include <iostream>

#ifdef NO_RESERVED_STD
export module std.io.IOStream;
#else
export module stdlib.io.IOStream;
#endif

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library input/output operations.
 */
export namespace stdlib::io {
    inline std::ostream& cout = std::cout;
    inline std::istream& cin = std::cin;
    inline std::ostream& cerr = std::cerr;
    inline std::ostream& clog = std::clog;

    inline std::wostream& wcout = std::wcout;
    inline std::wistream& wcin = std::wcin;
    inline std::wostream& wcerr = std::wcerr;
    inline std::wostream& wclog = std::wclog;
}
