/**
 * @file UIO.cppm
 * @brief Module file for Unix vectored I/O operations.
 *
 * This file contains the implementation of the Unix vectored I/O operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/uio.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.UIO;
#else
export module stdlib.os.unix.sys.UIO;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::readv;
    using ::writev;
    using ::preadv;
    using ::pwritev;
    using ::preadv64;
    using ::pwritev64;
    using ::preadv2;
    using ::pwritev2;
    using ::preadv64v2;
    using ::pwritev64v2;
    #endif
}
