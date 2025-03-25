/**
 * @file CWChar.cppm
 * @brief Module file for standard library wide character input/output operations.
 *
 * This file contains the implementation of the wide character input/output operations in the standard library.
 */

module;

#include <cwchar>

#ifdef NO_RESERVED_STD
export module std.io.CWChar;
#else
export module stdlib.io.CWChar;
#endif

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library input/output operations.
 */
export namespace stdlib::io {
    // Wide character unformatted I/O
    using std::fgetwc;
    using std::getwc;
    using std::fgetws;
    using std::fputwc;
    using std::putwc;
    using std::fputws;
    using std::getwchar;
    using std::putwchar;
    using std::ungetwc;

    // Wide character formatted I/O
    using std::wscanf;
    using std::fwscanf;
    using std::swscanf;
    using std::vwscanf;
    using std::vfwscanf;
    using std::vswscanf;
    using std::wprintf;
    using std::fwprintf;
    using std::swprintf;
    using std::vwprintf;
    using std::vfwprintf;
    using std::vswprintf;
}
