/**
 * @file User.cppm
 * @brief Module file for Unix GDB user operations.
 *
 * This file contains the implementation of the Unix GDB user operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/user.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.User;
#else
export module stdlib.os.unix.sys.User;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using UserFPRegsStruct = ::user_fpregs_struct;
    using UserRegsStruct = ::user_regs_struct;
    using User = ::user;
    #endif
}
