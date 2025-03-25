/**
 * @file NullPointerException.cppm
 * @brief Implementation of the NullPointerException class.
 *
 * This file contains the implementation of the NullPointerException class, which is used to handle 
 * errors related to passing null pointers (nullptr) in the application.
 */

export module engine.utility.Exceptions:NullPointerException;

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
     * @class NullPointerException
     * @brief Exception class for handling null pointer errors.
     *
     * @extends RuntimeException (std::runtime_error)
     * 
     * This class is used to represent an exception that occurs when a null pointer (nullptr) is 
     * unexpectedly encountered and dereferenced or used in a way that leads to an error. 
     */
    class NullPointerException: public RuntimeException {
    private:
        String message; ///< The exception message.
    public:
        /**
         * @brief Constructor that initialises the exception with a message.
         * @param msg The exception message.
         */
        NullPointerException(const String& msg):
            RuntimeException(msg) {}
        
        /**
         * @brief Get the exception message.
         * @return The exception message.
         */
        const char* what() const noexcept override {
            return message.c_str();
        }
    };
}