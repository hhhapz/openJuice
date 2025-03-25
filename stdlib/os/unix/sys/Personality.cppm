/**
 * @file Personality.cppm
 * @brief Module file for Unix operations.
 *
 * This file contains the implementation of the Unix operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/personality.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Personality;
#else
export module stdlib.os.unix.sys.Personality;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::personality;
    #endif
}
