/**
 * @file UTime.cppm
 * @brief Module file for Unix inode access operations.
 *
 * This file contains the implementation of the Unix inode access operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <utime.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.UTime;
#else
export module stdlib.os.unix.UTime;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using UTimBuf = ::utimbuf;

    using ::utime;
    #endif
}
