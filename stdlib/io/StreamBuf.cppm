/**
 * @file StreamBuf.cppm
 * @brief Module file for standard library stream buffer operations.
 *
 * This file contains the implementation of the stream buffer operations in the standard library.
 */

module;

#include <streambuf>

#ifdef NO_RESERVED_STD
export module std.io.StreamBuf;
#else
export module stdlib.io.StreamBuf;
#endif

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library input/output operations.
 */
export namespace stdlib::io {
    template<typename CharT>
    using BasicStreamBuf = std::basic_stringbuf<CharT>;

    using StreamBuf = std::streambuf;
    using WStreamBuf = std::wstreambuf;

    using std::swap;
}
