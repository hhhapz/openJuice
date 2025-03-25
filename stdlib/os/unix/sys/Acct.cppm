/**
 * @file Acct.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/acct.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Acct;
#else
export module stdlib.os.unix.sys.Acct;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using AcctV3 = ::acct_v3;

    using ::acct;
    #endif
}
