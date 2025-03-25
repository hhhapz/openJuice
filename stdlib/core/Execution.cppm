/**
 * @file Execution.cppm
 * @brief Module file for standard library execution policy operations.
 *
 * This file contains the implementation of the execution policy operations in the standard library.
 */

module;

#include <execution>

#ifdef NO_RESERVED_STD
export module std.core.Execution;
#else
export module stdlib.core.Execution;
#endif

/**
 * @namespace stdlib::execution
 * @brief Wrapper namespace for the standard library.
 */
export namespace stdlib::execution {
    template<typename T>
    using IsExecutionPolicy = std::is_execution_policy<T>;

    /**
     * @brief Wrapper namespace for standard library execution operations.
     */
    namespace Execution {
        using SequencedPolicy = std::execution::sequenced_policy;
        using ParallelPolicy = std::execution::parallel_policy;
        using ParallelUnsequencedPolicy = std::execution::parallel_unsequenced_policy;
        using UnsequencedPolicy = std::execution::unsequenced_policy;

        using std::execution::seq;
        using std::execution::par;
        using std::execution::par_unseq;
        using std::execution::unseq;
    }
}
