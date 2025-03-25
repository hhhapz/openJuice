/**
 * @file RegEx.cppm
 * @brief Module file for Unix regular expression operations.
 *
 * This file contains the implementation of the Unix regular expression operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <regex.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.RegEx;
#else
export module stdlib.os.unix.RegEx;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using REPatternBuffer = ::re_pattern_buffer;
    using RERegisters = ::re_registers;

    using ::re_set_syntax;
    using ::re_compile_pattern;
    using ::re_compile_fastmap;
    using ::re_search;
    using ::re_search_2;
    using ::re_match;
    using ::re_match_2;
    using ::re_set_registers;
    using ::regcomp;
    using ::regexec;
    using ::regerror;
    using ::regfree;
    #endif
}
