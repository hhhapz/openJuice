/**
 * @file Barrier.cppm
 * @brief Module file for standard library barrier operations.
 *
 * This file contains the implementation of the barrier operations in the standard library.
 */

module;

#include <barrier>

#ifdef NO_RESERVED_STD
export module std.concurrency.Barrier;
#else
export module stdlib.concurrency.Barrier;
#endif

/**
 * @namespace stdlib::concurrency
 * @brief Wrapper namespace for standard library concurrency operations.
 */
export namespace stdlib::concurrency {
    template<typename CompletionFunction>
    using Barrier = std::barrier<CompletionFunction>;
}
