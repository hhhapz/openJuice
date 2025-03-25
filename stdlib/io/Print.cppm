/**
 * @file Print.cppm
 * @brief Module file for standard library print operations.
 *
 * This file contains the implementation of the print operations in the standard library.
 */

module;

#include <print>

#ifdef NO_RESERVED_STD
export module std.io.Print;

import std.fmt.Format;
#else
export module stdlib.io.Print;

import stdlib.fmt.Format;
#endif

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library input/output operations.
 */
export namespace stdlib::io {
    using std::print;
    using std::println;
    using std::vprint_unicode;
    using std::vprint_nonunicode;

    using ::stdin;
    using ::stdout;
    using ::stderr;
}