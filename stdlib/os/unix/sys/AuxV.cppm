/**
 * @file AuxV.cppm
 * @brief Module file for Unix auxilliary vector operations.
 *
 * This file contains the implementation of the Unix auxilliary vector operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/auxv.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.AuxV;
#else
export module stdlib.os.unix.sys.AuxV;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::getauxval;
    #endif
}
