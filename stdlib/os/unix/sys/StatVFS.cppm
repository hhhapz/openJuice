/**
 * @file StatVFS.cppm
 * @brief Module file for Unix filesystem information operations.
 *
 * This file contains the implementation of the Unix filesystem information operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/statvfs.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.StatVFS;
#else
export module stdlib.os.unix.sys.StatVFS;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::statvfs;
    using ::statvfs64;
    using ::fstatvfs;
    using ::fstatvfs64;
    #endif
}
