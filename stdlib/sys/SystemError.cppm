/**
 * @file SystemError.cppm
 * @brief Module file for standard library system error classes.
 *
 * This file contains the implementation of error classes in the standard library.
 */

module;

#include <system_error>

#ifdef NO_RESERVED_STD
export module std.sys.SystemError;
#else
export module stdlib.sys.SystemError;
#endif

/**
 * @namespace stdlib::sys
 * @brief Wrapper namespace for standard library system operations.
 */
export namespace stdlib::sys {
    using ErrorCategory = std::error_category;
    using ErrorCondition = std::error_condition;
    using ErrC = std::errc;
    using ErrorCode = std::error_code;

    using SystemException = std::system_error;

    template<typename T>
    using IsErrorCodeEnum = std::is_error_code_enum<T>;

    template<typename T>
    using IsErrorConditionEnum = std::is_error_code_enum<T>;

    using std::generic_category;
    using std::system_category;
    using std::make_error_code;
    using std::make_error_condition;

    using std::hash;
}
