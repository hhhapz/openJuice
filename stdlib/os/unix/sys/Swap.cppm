/**
 * @file Swap.cppm
 * @brief Module file for Unix swapping enable/disable operations.
 *
 * This file contains the implementation of the Unix swapping enable/disable operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/swap.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Swap;
#else
export module stdlib.os.unix.sys.Swap;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::swapon;
    using ::swapoff;
    #endif
}
