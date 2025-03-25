/**
 * @file Latch.cppm
 * @brief Module file for standard library latch operations.
 *
 * This file contains the implementation of the latch operations in the standard library.
 */

module;

#include <latch>

#ifdef NO_RESERVED_STD
export module std.concurrency.Latch;
#else
export module stdlib.concurrency.Latch;
#endif

/**
 * @namespace stdlib::concurrency
 * @brief Wrapper namespace for standard library concurrency operations.
 */
export namespace stdlib::concurrency {
    using Latch = std::latch;
}
