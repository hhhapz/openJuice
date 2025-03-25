/**
 * @file UTMPX.cppm
 * @brief Module file for Unix user account database operations.
 *
 * This file contains the implementation of the Unix user account database operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <utmpx.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.UTMPX;
#else
export module stdlib.os.unix.UTMPX;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::setutxent;
    using ::endutxent;
    using ::getutxent;
    using ::getutxid;
    using ::getutxline;
    using ::pututxline;
    using ::utmpxname;
    using ::updwtmpx;
    using ::getutmp;
    using ::getutmpx;
    #endif
}
