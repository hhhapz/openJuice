/**
 * @file Mutex.cppm
 * @brief Module file for standard library semaphore operations.
 *
 * This file contains the implementation of the semaphore operations in the standard library.
 */

module;

#include <semaphore>

#ifdef NO_RESERVED_STD
export module std.concurrency.Semaphore;
#else
export module stdlib.concurrency.Semaphore;
#endif

/**
 * @namespace stdlib::concurrency
 * @brief Wrapper namespace for standard library concurrency operations.
 */
export namespace stdlib::concurrency {
    using CountingSemaphore = std::counting_semaphore<>;

    using BinarySemaphore = std::binary_semaphore;
}
