/**
 * @file Pwd.cppm
 * @brief Module file for Unix password access/control operations.
 *
 * This file contains the implementation of the Unix password access/control operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <pwd.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.Pwd;
#else
export module stdlib.os.unix.Pwd;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using Passwd = ::passwd;

    using ::setpwent;
    using ::endpwent;
    using ::getpwent;
    using ::fgetpwent;
    using ::putpwent;
    using ::getpwuid;
    using ::getpwnam;
    using ::getpwent_r;
    using ::getpwuid_r;
    using ::getpwnam_r;
    using ::fgetpwent_r;
    using ::getpw;
    #endif
}
