/**
 * @file ChatClient.cppm
 * @brief Implementation of the ChatClient class.
 *
 * This file contains the implementation of the ChatClient class, which is used to manage chat client connections.
 */

module;

#include <boost/asio.hpp>

export module chat.Chat:ChatClient;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.concurrency;
import std.io;
import std.text;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.concurrency;
import stdlib.io;
import stdlib.text;
#endif

import engine.managers.GlobalSettings;
import engine.utility.EngineUtility;

using namespace collections;
using namespace concurrency;

using namespace boost::asio;

/**
 * @class ChatClient
 * @brief Class for managing chat client connections.
 * 
 * The ChatClient class manages chat client connections and handles communication with the chat server.
 */
export class ChatClient {
private:
    ip::tcp::socket clientSocket; ///< Socket for the chat client.

    /**
     * @brief Start the chat client.
     */
    void startChat() {
        DebugLogger::getInstance().log("Starting chat");
        String message;
        while (io::getline(io::cin, message)) {
            message += "\n";
            write(clientSocket, buffer(message));
        }
    }

    /**
     * @brief Start listening for messages from the server.
     */
    void startListening() {
        std::thread([this]() -> void {
            try {
                boost::asio::streambuf buffer;
                while (true) {
                    read_until(clientSocket, buffer, '\n');
                    io::IStream is(&buffer);
                    String message;
                    io::getline(is, message);
                    io::print("\n[CHAT] {}\n> ", message);
                    io::cout.flush();
                }
            } catch (...) {
                io::print(stderr, "Disconnected from server.\n");
            }
        }).detach();
    }
public:
    /**
     * @brief Constructor to initialise a ChatClient object.
     * @param ioContext The IO context to use.
     * @param host The host to connect to.
     * @param port The port to connect to.
     */
    ChatClient(boost::asio::io_context& ioContext, const String& host, i16 port):
        clientSocket(ioContext) {
        ip::tcp::resolver resolver(ioContext);
        ip::tcp::resolver::results_type endpoints = resolver.resolve(host, string::to_string(port));
        connect(clientSocket, endpoints);
        startListening();
        startChat();
    }
};