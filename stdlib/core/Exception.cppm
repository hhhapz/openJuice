/**
 * @file Exceptions.cppm
 * @brief Module file for importing exceptions from the standard library.
 *
 * This file contains the implementation of the exception operations in the standard library.
 */

module;

#include <exception>
#include <stdexcept>

#ifdef NO_RESERVED_STD
export module std.core.Exceptions;
#else
export module stdlib.core.Exceptions;
#endif

/**
 * @namespace stdlib
 * @brief Wrapper namespace for the standard library.
 */
export namespace stdlib {
    using Exception = std::exception;

    using BadExceptionException = std::bad_exception;
    using DomainException = std::domain_error;
    using InvalidArgumentException = std::invalid_argument;
    using LengthException = std::length_error;
    using LogicException = std::logic_error;
    using OutOfRangeException = std::out_of_range;
    using OverflowException = std::overflow_error;
    using RuntimeException = std::runtime_error;
    using UnderflowException = std::underflow_error;

    using NestedException = std::nested_exception;
    using TerminateHandler = std::terminate_handler;
    using ExceptionPtr = std::exception_ptr;

    using std::uncaught_exceptions;
    using std::make_exception_ptr;
    using std::current_exception;
    using std::rethrow_exception;
    using std::throw_with_nested;
    using std::rethrow_if_nested;
    using std::terminate;
    using std::get_terminate;
    using std::set_terminate;
}
