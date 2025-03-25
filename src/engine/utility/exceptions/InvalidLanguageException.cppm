/**
 * @file InvalidLanguageException.cppm
 * @brief Implementation of the InvalidLanguageException class.
 *
 * This file contains the implementation of the InvalidLanguageException class, which is used to handle invalid language exceptions.
 */

export module engine.utility.Exceptions:InvalidLanguageException;

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
     * @class InvalidLanguageException
     * @brief Exception class for invalid languages.
     *
     * @extends InvalidArgumentException (std::invalid_argument)
     * 
     * The InvalidLanguageException class is used to handle exceptions related to invalid languages.
     */
    class InvalidLanguageException: public InvalidArgumentException {
    private:
        String message; ///< The exception message.
    public:
        /**
         * @brief Constructor that initialises the exception with a message.
         * @param msg The exception message.
         */
        InvalidLanguageException(const String& msg):
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