/**
 * @file fmt.cppm
 * @brief Module file for standard library format and regex operations.
 *
 * This file contains the imports for the text formatting operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.fmt;
#else
export module stdlib.fmt;
#endif

#ifdef NO_RESERVED_STD
export import std.fmt.CharConv;
export import std.fmt.CIntTypes;
export import std.fmt.Format;
#else
export import stdlib.fmt.CharConv;
export import stdlib.fmt.CIntTypes;
export import stdlib.fmt.Format;
#endif

export using namespace stdlib;
