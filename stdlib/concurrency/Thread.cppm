/**
 * @file Thread.cppm
 * @brief Module file for standard library thread operations.
 *
 * This file contains the implementation of the thread operations in the standard library.
 */

module;

#include <thread>

#ifdef NO_RESERVED_STD
export module std.concurrency.Thread;
#else
export module stdlib.concurrency.Thread;
#endif

/**
 * @namespace stdlib::concurrency
 * @brief Wrapper namespace for standard library concurrency operations.
 */
export namespace stdlib::concurrency {
    using Thread = std::thread;
    using JThread = std::jthread;

    /**
     * @brief Namespace for operations on the current thread.
     */
    namespace this_thread {
        using std::this_thread::yield;
        using std::this_thread::get_id;
        using std::this_thread::sleep_for;
        using std::this_thread::sleep_until;
    }

    using std::swap;
}
