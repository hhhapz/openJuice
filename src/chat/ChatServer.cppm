/**
 * @file ChatServer.cppm
 * @brief Implementation of the ChatServer class.
 *
 * This file contains the implementation of the ChatServer class, which is used to manage chat server connections.
 */

module;

#include <boost/asio.hpp>
#include <boost/system/detail/error_code.hpp>

export module chat.Chat:ChatServer;

import :ChatSession;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.mem;
import std.util;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.mem;
import stdlib.util;
#endif

using namespace collections;
using mem::SharedPtr;

using namespace boost::asio;

/**
 * @class ChatServer
 * @brief Class for managing chat server connections.
 * 
 * The ChatServer class manages chat server connections and handles incoming client connections.
 */
export class ChatServer {
private:
    ip::tcp::acceptor serverAcceptor; ///< Acceptor for incoming connections.
    Vector<SharedPtr<ChatSession>> clients; ///< List of connected clients.

    /**
     * @brief Accept an incoming connection.
     */
    void acceptConnection() {
        serverAcceptor.async_accept(
            [this](boost::system::error_code ec, ip::tcp::socket socket) -> void {
                if (!ec)    
                    mem::make_shared<ChatSession>(util::move(socket), clients)->start();
                acceptConnection();
            }
        );
    }
public:
    /**
     * @brief Constructor to initialise a ChatServer object.
     * @param ioContext The IO context to use.
     * @param port The port to listen on.
     */
    ChatServer(io_context& ioContext, i16 port):
        serverAcceptor(ioContext, ip::tcp::endpoint(ip::tcp::v4(), port)) {
        acceptConnection();
    }
};