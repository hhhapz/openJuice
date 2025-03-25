/**
 * @file Wait.cppm
 * @brief Module file for Unix wait operations.
 *
 * This file contains the implementation of the Unix wait operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/wait.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Wait;
#else
export module stdlib.os.unix.sys.Wait;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using ::wait;
    using ::waitpid;
    using ::waitid;
    using ::wait3;
    using ::wait4;
    #endif
}
