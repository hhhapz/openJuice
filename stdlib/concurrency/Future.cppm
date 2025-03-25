/**
 * @file Future.cppm
 * @brief Module file for standard library future operations.
 *
 * This file contains the implementation of the future operations in the standard library.
 */

module;

#include <future>

#ifdef NO_RESERVED_STD
export module std.concurrency.Future;
#else
export module stdlib.concurrency.Future;
#endif

/**
 * @namespace stdlib::concurrency
 * @brief Wrapper namespace for standard library concurrency operations.
 */
export namespace stdlib::concurrency {
    template<typename T>
    using Promise = std::promise<T>;

    template<typename T>
    using PackagedTask = std::packaged_task<T>;

    template<typename T>
    using Future = std::future<T>;

    template<typename T>
    using SharedFuture = std::shared_future<T>;

    using Launch = std::launch;
    using FutureStatus = std::future_status;
    using FutureException = std::future_error;
    using FutureErrC = std::future_errc;

    using std::async;
    using std::future_category;

    using std::swap;
}
