/**
 * @file Socket.cppm
 * @brief Module file for Unix Berkley sockets operations.
 *
 * This file contains the implementation of the Unix Berkley sockets operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <sys/socket.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.sys.Socket;
#else
export module stdlib.os.unix.sys.Socket;
#endif

/**
 * @namespace stdlib::os::posix::sys
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::sys {
    #ifdef __unix__
    using MMsgHdr = ::mmsghdr;

    using ::socket;
    using ::socketpair;
    using ::bind;
    using ::getsockname;
    using ::connect;
    using ::getpeername;
    using ::send;
    using ::recv;
    using ::sendto;
    using ::recvfrom;
    using ::sendmsg;
    using ::sendmmsg;
    using ::recvmsg;
    using ::recvmmsg;
    using ::getsockopt;
    using ::setsockopt;
    using ::listen;
    using ::accept;
    using ::accept4;
    using ::shutdown;
    using ::sockatmark;
    using ::isfdtype;
    #endif
}
