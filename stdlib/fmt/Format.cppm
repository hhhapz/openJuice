/**
 * @file Format.cppm
 * @brief Module file for standard library format operations.
 *
 * This file contains the implementation of the format operations in the standard library.
 */

module;

#include <format>

#ifdef NO_RESERVED_STD
export module std.fmt.Format;
#else
export module stdlib.fmt.Format;
#endif

/**
 * @namespace stdlib::fmt
 * @brief Wrapper namespace for standard library format operations.
 */
export namespace stdlib::fmt {
    using std::formattable;

    using FormatException = std::format_error;

    template<typename T>
    using Formatter = std::formatter<T>;

    template<typename CharT>
    using BasicFormatParseContext = std::basic_format_parse_context<CharT>;

    using FormatParseContext = std::format_parse_context;
    using WFormatParseContext = std::wformat_parse_context;

    template<typename Out, typename CharT>
    using BasicFormatContext = std::basic_format_context<Out, CharT>;

    using FormatContext = std::format_context;
    using WFormatContext = std::wformat_context;

    template<typename Context>
    using BasicFormatArg = std::basic_format_arg<Context>;

    template<typename Context>
    using BasicFormatArgs = std::basic_format_args<Context>;

    using FormatArgs = std::format_args;
    using WFormatArgs = std::wformat_args;

    template<typename CharT, typename... Args>
    using BasicFormatString = std::basic_format_string<CharT, Args...>;

    template<typename... Args>
    using FormatString = std::format_string<Args...>;

    template<typename... Args>
    using WFormatString = std::wformat_string<Args...>;

    using std::format;
    using std::format_to;
    using std::format_to_n;
    using std::formatted_size;
    using std::vformat;
    using std::vformat_to;
    using std::make_format_args;
    using std::make_wformat_args;
}
