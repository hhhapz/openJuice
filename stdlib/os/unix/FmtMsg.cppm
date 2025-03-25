/**
 * @file FmtMsg.cppm
 * @brief Module file for Unix message display structure operations.
 *
 * This file contains the implementation of the Unix message display structure operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <fmtmsg.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.FmtMsg;
#else
export module stdlib.os.unix.FmtMsg;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::fmtmsg;
    using ::addseverity;
    #endif
}
