/**
 * @file WordExp.cppm
 * @brief Module file for Unix word expansion operations.
 *
 * This file contains the implementation of the Unix word expansion operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <wordexp.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.WordExp;
#else
export module stdlib.os.unix.WordExp;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::wordexp;
    using ::wordfree;
    #endif
}
