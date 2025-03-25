/**
 * @file SpanStream.cppm
 * @brief Module file for standard library spanstream operations.
 *
 * This file contains the implementation of the spanstream operations in the standard library.
 */

module;

#include <spanstream>

#ifdef NO_RESERVED_STD
export module std.io.SpanStream;
#else
export module stdlib.io.SpanStream;
#endif

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library IO operations.
 */
export namespace stdlib::io {
    template<typename CharT>
    using BasicSpanBuf = std::basic_spanbuf<CharT>;

    template<typename CharT>
    using BasicISpanStream = std::basic_ispanstream<CharT>;

    template<typename CharT>
    using BasicOSpanStream = std::basic_ospanstream<CharT>;

    template<typename CharT>
    using BasicSpanStream = std::basic_spanstream<CharT>;

    using SpanBuf = std::spanbuf;
    using WSpanBuf = std::wspanbuf;
    using ISpanStream = std::ispanstream;
    using WISpanstream = std::wispanstream;
    using OSpanStream = std::ospanstream;
    using WOSpanStream = std::wospanstream;
    using SpanStream = std::spanstream;
    using WSpanStream = std::wspanstream;

    using std::swap;
}
