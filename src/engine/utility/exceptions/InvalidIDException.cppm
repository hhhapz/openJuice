/**
 * @file InvalidIDException.cppm
 * @brief Implementation of the InvalidIDException class.
 *
 * This file contains the implementation of the InvalidIDException class, which is used to handle invalid ID in ID queries.
 */

export module engine.utility.Exceptions:InvalidIDException;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
#else
import stdlib.core;
import stdlib.collections;
#endif

/**
 * @namespace exceptions
 * @brief Contains all custom exceptions thrown by the program
 */
export namespace exceptions {
    /**
     * @class InvalidIDException
     * @brief Exception class for invalid IDs.
     *
     * @extends InvalidArgumentException (std::invalid_argument)
     * 
     * The InvalidIDException class is used to handle exceptions related to invalid IDs in ID queries.
     */
    class InvalidIDException: public InvalidArgumentException {
    private:
        String message; ///< The exception message.
    public:
        /**
         * @brief Constructor that initialises the exception with a message.
         * @param msg The exception message.
         */
        InvalidIDException(const String& msg):
            InvalidArgumentException(msg) {}
        
        /**
         * @brief Get the exception message.
         * @return The exception message.
         */
        const char* what() const noexcept override {
            return message.c_str();
        }
    };
}