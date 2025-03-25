/**
 * @file InvalidKeyException.cppm
 * @brief Implementation of the InvalidKeyException class.
 *
 * This file contains the implementation of the InvalidKeyException class, which is used to handle invalid keys in TextManager key queries.
 */

export module engine.utility.Exceptions:InvalidKeyException;

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
     * @class InvalidKeyException
     * @brief Exception class for invalid keys.
     *
     * @extends InvalidArgumentException (std::invalid_argument)
     * 
     * The InvalidKeyException class is used to handle exceptions related to invalid keys in TextManager key queries.
     */
    class InvalidKeyException: public InvalidArgumentException {
    private:
        String message; ///< The exception message.
    public:
        /**
         * @brief Constructor that initialises the exception with a message.
         * @param msg The exception message.
         */
        InvalidKeyException(const String& msg):
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