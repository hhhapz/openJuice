/**
 * @file TTYChars.cppm
 * @brief Module file for Unix terminal handling constants.
 *
 * This file contains the implementation of the Unix terminal handling constants from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/ttychars.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.TTYChars;
#else
export module stdlib.os.unix.sys.TTYChars;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using TTYChars = ::ttychars;
    #endif
}
