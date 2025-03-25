/**
 * @file StackTrace.cppm
 * @brief Module file for standard library stacktrace operations.
 *
 * This file contains the implementation of the stack trace operations in the standard library.
 */

module;

#include <stacktrace>

#ifdef NO_RESERVED_STD
export module std.util.StackTrace;
#else
export module stdlib.util.StackTrace;
#endif

/**
 * @namespace stdlib::util
 * @brief Wrapper namespace for standard library utility operations.
 */
export namespace stdlib::util {
    using StackTraceEntry = std::stacktrace_entry;

    template<typename Allocator>
    using BasicStackTrace = std::basic_stacktrace<Allocator>;

    using std::hash;
    using std::swap;

    using std::to_string;
    using std::operator<<;
}
