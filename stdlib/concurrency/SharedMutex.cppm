/**
 * @file Mutex.cppm
 * @brief Module file for standard library shared mutex operations.
 *
 * This file contains the implementation of the shared mutex operations in the standard library.
 */

module;

#include <shared_mutex>

#ifdef NO_RESERVED_STD
export module std.concurrency.SharedMutex;
#else
export module stdlib.concurrency.SharedMutex;
#endif

/**
 * @namespace stdlib::concurrency
 * @brief Wrapper namespace for standard library concurrency operations.
 */
export namespace stdlib::concurrency {
    using SharedMutex = std::shared_mutex;
    using SharedTimedMutex = std::shared_timed_mutex;

    template<typename T>
    using SharedLock = std::shared_lock<T>;

    using std::swap;
}
