/**
 * @file Select.cppm
 * @brief Module file for Unix fd_set type and select/pselect declaration operations.
 *
 * This file contains the implementation of the Unix fd_set type and select/pselect declaration operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/select.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Select;
#else
export module stdlib.os.unix.sys.Select;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::select;
    using ::pselect;
    #endif
}
