/**
 * @file Monetary.cppm
 * @brief Module file for Unix monetary unit string formatting operations.
 *
 * This file contains the implementation of the Unix monetary unit string formatting operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <monetary.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.Monetary;
#else
export module stdlib.os.unix.Monetary;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::strfmon;
    using ::strfmon_l;
    #endif
}
