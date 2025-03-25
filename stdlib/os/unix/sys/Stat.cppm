/**
 * @file Stat.cppm
 * @brief Module file for Unix file information operations.
 *
 * This file contains the implementation of the Unix file information operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/stat.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Stat;
#else
export module stdlib.os.unix.sys.Stat;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::stat;
    using ::fstat;
    using ::stat64;
    using ::fstat64;
    using ::fstatat;
    using ::fstatat64;
    using ::lstat;
    using ::lstat64;
    using ::chmod;
    using ::lchmod;
    using ::fchmod;
    using ::fchmodat;
    using ::umask;
    using ::getumask;
    using ::mkdir;
    using ::mkdirat;
    using ::mknod;
    using ::mknodat;
    using ::mkfifo;
    using ::mkfifoat;
    using ::utimensat;
    using ::futimens;
    #endif
}
