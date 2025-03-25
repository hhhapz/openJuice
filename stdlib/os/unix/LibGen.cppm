/**
 * @file LibGen.cppm
 * @brief Module file for Unix pathname manipulation operations.
 *
 * This file contains the implementation of the Unix pathname manipulation operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <libgen.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.LibGen;
#else
export module stdlib.os.unix.LibGen;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::dirname;
    #endif
}
