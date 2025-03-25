/**
 * @file FnMatch.cppm
 * @brief Module file for Unix filename matching operations.
 *
 * This file contains the implementation of the Unix filename matching operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <fnmatch.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.FnMatch;
#else
export module stdlib.os.unix.FnMatch;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::fnmatch;
    #endif
}
