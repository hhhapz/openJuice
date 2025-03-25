/**
 * @file XAttr.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/xattr.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.XAttr;
#else
export module stdlib.os.unix.sys.XAttr;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::setxattr;
    using ::lsetxattr;
    using ::fsetxattr;
    using ::getxattr;
    using ::lgetxattr;
    using ::fgetxattr;
    using ::listxattr;
    using ::llistxattr;
    using ::flistxattr;
    using ::removexattr;
    using ::lremovexattr;
    using ::fremovexattr;
    #endif
}
