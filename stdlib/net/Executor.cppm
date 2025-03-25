/**
 * @file Executor.cppm
 * @brief Module file for (experimental) standard library networking executor operations.
 *
 * This file contains the implementation of the (experimental) networking executor operations in the standard library.
 */

module;

#ifdef __GNUC__
#ifdef EXPERIMENTAL_STD
#include <experimental/executor>
#endif
#endif

#ifdef NO_RESERVED_STD
export module std.net.Executor;
#else
export module stdlib.net.Executor;
#endif

/**
 * @namespace stdlib::net
 * @brief Wrapper namespace for (experimental) standard library networking operations.
 */
export namespace stdlib::net {
    #ifdef EXPERIMENTAL_STD
    template<typename CompletionToken, typename Signature>
    using AsyncResult = std::experimental::net::async_result<CompletionToken, Signature>;

    template<typename CompletionToken, typename Signature>
    using AsyncCompletion = std::experimental::net::async_completion<CompletionToken, Signature>;

    using Executor = std::experimental::net::executor;

    template<typename T, typename Executor>
    using ExecutorBinder = std::experimental::net::executor_binder<T, Executor>;

    using ExecutionContext = std::experimental::net::execution_context;
    using SystemExecutor = std::experimental::net::system_executor;

    template<typename Executor>
    using ExecutorWorkGuard = std::experimental::net::executor_work_guard<Executor>;

    using ForkEvent = std::experimental::net::fork_event;

    template<typename Executor>
    using Strand = std::experimental::net::strand<Executor>;

    using SystemContext = std::experimental::net::system_context;
    using SystemExecutor = std::experimental::net::system_executor;

    using BadExecutorException = std::experimental::net::bad_executor;
    using ServiceAlreadyExistsException = std::experimental::net::service_already_exists;
    #endif
}
