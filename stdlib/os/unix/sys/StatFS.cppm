/**
 * @file StatFS.cppm
 * @brief Module file for Unix filesystem information retrieval operations.
 *
 * This file contains the implementation of the Unix filesystem information retrieval operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/statfs.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.StatFS;
#else
export module stdlib.os.unix.sys.StatFS;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::statfs;
    using ::statfs64;
    using ::fstatfs;
    using ::fstatfs64;
    #endif
}
