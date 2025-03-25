/**
 * @file Cpio.cppm
 * @brief Module file for Unix message queue operations.
 *
 * This file contains the implementation of the Unix message queue operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <mqueue.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.MQueue;
#else
export module stdlib.os.unix.MQueue;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::mq_open;
    using ::mq_close;
    using ::mq_getattr;
    using ::mq_setattr;
    using ::mq_unlink;
    using ::mq_notify;
    using ::mq_receive;
    using ::mq_send;
    using ::mq_timedreceive;
    using ::mq_timedsend;
    #endif
}
