/**
 * @file Msg.cppm
 * @brief Module file for Unix message queue operations.
 *
 * This file contains the implementation of the Unix message queue operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/msg.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Msg;
#else
export module stdlib.os.unix.sys.Msg;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using MsgBuf = ::msgbuf;

    using ::msgctl;
    using ::msgget;
    using ::msgrcv;
    using ::msgsnd;
    #endif
}
