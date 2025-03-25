/**
 * @file CharConv.cppm
 * @brief Module file for standard library character conversion operations.
 *
 * This file contains the implementation of the character conversion operations in the standard library.
 */

module;

#include <charconv>

#ifdef NO_RESERVED_STD
export module std.fmt.CharConv;
#else
export module stdlib.fmt.CharConv;
#endif

/**
 * @namespace stdlib::fmt
 * @brief Wrapper namespace for standard library format operations.
 */
export namespace stdlib::fmt {
    using CharsFormat = std::chars_format;
    using FromCharsResult = std::from_chars_result;
    using ToCharsResult = std::to_chars_result;

    using std::from_chars;
    using std::to_chars;
}
