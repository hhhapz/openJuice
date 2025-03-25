/**
 * @file Random.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/random.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Random;
#else
export module stdlib.os.unix.sys.Random;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::getrandom;
    using ::getentropy;
    #endif
}
