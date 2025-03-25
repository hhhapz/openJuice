/**
 * @file ChatSession.cppm
 * @brief Implementation of the ChatSession class.
 *
 * This file contains the implementation of the ChatSession class, which is used to manage individual chat sessions.
 */

module;

#include <boost/asio.hpp>
#include <boost/system/detail/error_code.hpp>

export module chat.Chat:ChatSession;

#ifdef NO_RESERVED_STD
import std.algorithm;
import std.core;
import std.collections;
import std.io;
import std.mem;
import std.util;
#else
import stdlib.algorithm;
import stdlib.core;
import stdlib.collections;
import stdlib.io;
import stdlib.mem;
import stdlib.util;
#endif

using namespace collections;
using mem::SharedPtr;

using namespace boost::asio;

/**
 * @class ChatSession
 * @brief Class for managing individual chat sessions.
 * 
 * The ChatSession class manages individual chat sessions and handles communication with clients.
 */
export class ChatSession: public mem::EnableSharedFromThis<ChatSession> {
private:
    ip::tcp::socket sessionSocket; ///< Socket for the chat session.
    String inputBuffer; ///< Buffer for incoming messages.
    Vector<SharedPtr<ChatSession>>& clients; ///< List of connected clients.

    /**
     * @brief Broadcast a message to all clients.
     * @param msg The message to broadcast.
     */
    void broadcast(const String& msg) {
        for (SharedPtr<ChatSession>& client: clients) {
            if (client != shared_from_this())
                client->deliver(msg);
        }
    }

    /**
     * @brief Remove the client from the list of connected clients.
     */
    void removeClient() {
        clients.erase(
            algorithm::remove(clients.begin(), clients.end(), shared_from_this()),
            clients.end()
        );
    }

    /**
     * @brief Read a message from the client.
     */
    void readMessage() {
        SharedPtr<ChatSession> self(shared_from_this());
        async_read_until(sessionSocket, dynamic_buffer(inputBuffer), '\n',
            [this, self](boost::system::error_code ec, usize length) -> void {
                if (!ec) {
                    String message = inputBuffer.substr(0, length);
                    inputBuffer.erase(0, length);
                    io::print("Received: {}", message);
                    broadcast(message);
                    readMessage();
                } else
                    removeClient();
        });
    }
public:
    /**
     * @brief Constructor to initialise a ChatSession object.
     * @param socket The socket for the chat session.
     * @param clients The list of connected clients.
     */
    ChatSession(ip::tcp::socket socket, Vector<SharedPtr<ChatSession>>& clients):
        sessionSocket{util::move(socket)}, clients{clients} {}
    
    /**
     * @brief Start the chat session.
     */
    void start() {
        clients.push_back(shared_from_this());
        readMessage();
    }

    /**
     * @brief Deliver a message to the client.
     * @param msg The message to deliver.
     */
    void deliver(const String& msg) {
        async_write(sessionSocket, buffer(msg),
            [](boost::system::error_code, usize) -> void {}
        );
    }
};