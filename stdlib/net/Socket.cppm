/**
 * @file Buffer.cppm
 * @brief Module file for (experimental) standard library networking socket operations.
 *
 * This file contains the implementation of the (experimental) networking socket operations in the standard library.
 */


module;

#ifdef __GNUC__
#ifdef EXPERIMENTAL_STD
#include <experimental/socket>
#endif
#endif

#ifdef NO_RESERVED_STD
export module std.net.Socket;
#else
export module stdlib.net.Socket;
#endif

/**
 * @namespace stdlib::net
 * @brief Wrapper namespace for (experimental) standard library networking operations.
 */
export namespace stdlib::net {
    #ifdef EXPERIMENTAL_STD
    using SocketBase = std::experimental::net::socket_base;

    template<typename Protocol>
    using BasicSocket = std::experimental::net::basic_socket<Protocol>;

    template<typename Protocol>
    using BasicDatagramSocket = std::experimental::net::basic_datagram_socket<Protocol>;

    template<typename Protocol>
    using BasicStreamSocket = std::experimental::net::basic_stream_socket<Protocol>;

    template<typename Protocol>
    using BasicSocketAcceptor = std::experimental::net::basic_socket_acceptor<Protocol>;

    template<typename Protocol>
    using BasicSocketStreamBuf = std::experimental::net::basic_socket_streambuf<Protocol>;

    template<typename Protocol>
    using BasicSocketIOStream = std::experimental::net::basic_socket_iostream<Protocol>;
    #endif
}
