/**
 * @file NLTypes.cppm
 * @brief Module file for Unix localisation message catalogue operations.
 *
 * This file contains the implementation of the Unix localisation message catalogue operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <nl_types.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.NLTypes;
#else
export module stdlib.os.unix.NLTypes;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::catopen;
    using ::catgets;
    using ::catclose;
    #endif
}
