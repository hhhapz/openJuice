/**
 * @file Mutex.cppm
 * @brief Module file for standard library mutex operations.
 *
 * This file contains the implementation of the mutex operations in the standard library.
 */

module;

#include <mutex>

#ifdef NO_RESERVED_STD
export module std.concurrency.Mutex;
#else
export module stdlib.concurrency.Mutex;
#endif

/**
 * @namespace stdlib::concurrency
 * @brief Wrapper namespace for standard library concurrency operations.
 */
export namespace stdlib::concurrency {
    using Mutex = std::mutex;
    using TimedMutex = std::timed_mutex;
    using RecursiveMutex = std::recursive_mutex;
    using RecursiveTimedMutex = std::recursive_timed_mutex;

    template<typename _Mutex>
    using LockGuard = std::lock_guard<_Mutex>;

    template<typename _Mutex>
    using UniqueLock = std::unique_lock<_Mutex>;

    template<typename... _MutexTypes>
    using ScopedLock = std::scoped_lock<_MutexTypes...>;

    using std::swap;
}
