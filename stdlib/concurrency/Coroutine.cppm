/**
 * @file Coroutine.cppm
 * @brief Module file for standard library coroutine operations.
 *
 * This file contains the implementation of the coroutine operations in the standard library.
 */

module;

#include <coroutine>

#ifdef NO_RESERVED_STD
export module std.concurrency.Coroutine;
#else
export module stdlib.concurrency.Coroutine;
#endif

/**
 * @namespace stdlib::concurrency
 * @brief Wrapper namespace for standard library concurrency operations.
 */
export namespace stdlib::concurrency {
    template<typename R, typename... Args>
    using CoroutineTraits = std::coroutine_traits<R(Args...)>;

    template<typename R, typename... Args>
    using CoroutineHandle = std::coroutine_handle<R(Args...)>;

    using NoopCoroutinePromise = std::noop_coroutine_promise;
    using NoopCoroutineHandle = std::noop_coroutine_handle;
    using SuspendNever = std::suspend_never;
    using SuspendAlways = std::suspend_always;

    using std::noop_coroutine;
}
