/**
 * @file Messages.cppm
 * @brief Implementation of the Messages namespace.
 *
 * This file contains the implementation of the Messages namespace, which is used to print various messages.
 */

export module engine.utility.Messages;

#ifdef NO_RESERVED_STD
import std.core;
import std.io;
#else
import stdlib.core;
import stdlib.io;
#endif

/**
 * @namespace messages
 * @brief Namespace for printing messages.
 */
export namespace messages {
    /**
     * @brief Print the help message.
     */
    void printHelp() {
        io::println("Help message");
    }

    /**
     * @brief Print the credits message.
     */
    void printCredits() {
        io::println("Version: 0.0.x");
        io::println("Credits message");
    }
}