/**
 * @file UTSName.cppm
 * @brief Module file for Unix operating system information operations.
 *
 * This file contains the implementation of the Unix operating system information operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/utsname.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.UTSName;
#else
export module stdlib.os.unix.sys.UTSName;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using UTSName = ::utsname;

    using ::uname;
    #endif
}
