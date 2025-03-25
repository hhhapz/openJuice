/**
 * @file Glob.cppm
 * @brief Module file for Unix globbing operations.
 *
 * This file contains the implementation of the Unix globbing operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <glob.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.Glob;
#else
export module stdlib.os.unix.Glob;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using Stat = ::stat;
    using Stat64 = ::stat64;

    using Glob_t = ::glob_t;

    using ::glob;
    using ::globfree;
    using ::glob64;
    using ::globfree64;

    using ::glob_pattern_p;
    #endif
}
