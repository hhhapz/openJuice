/**
 * @file ConditionVariable.cppm
 * @brief Module file for standard library condition variable operations.
 *
 * This file contains the implementation of the condition variable operations in the standard library.
 */

module;

#include <condition_variable>

#ifdef NO_RESERVED_STD
export module std.concurrency.ConditionVariable;
#else
export module stdlib.concurrency.ConditionVariable;
#endif

/**
 * @namespace stdlib::concurrency
 * @brief Wrapper namespace for standard library concurrency operations.
 */
export namespace stdlib::concurrency {
    using ConditionVariable = std::condition_variable;
    using ConditionVariableAny = std::condition_variable_any;
    using CVStatus = std::cv_status;

    using std::notify_all_at_thread_exit;
}
