/**
 * @file text.cppm
 * @brief Module file for standard library text manipulation operations.
 *
 * This file contains the imports for the text manipulation operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.text;
#else
export module stdlib.text;
#endif

#ifdef NO_RESERVED_STD
export import std.text.CString;
export import std.text.Regex;
export import std.text.String;
export import std.text.StringView;
#else
export import stdlib.text.CString;
export import stdlib.text.Regex;
export import stdlib.text.String;
export import stdlib.text.StringView;
#endif

export using namespace stdlib;
