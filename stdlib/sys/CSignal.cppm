/**
 * @file CSignal.cppm
 * @brief Module file for standard library C-style signal operations.
 *
 * This file contains the implementation of the C-style signal operations in the standard library.
 */

module;

#include <csignal>

#ifdef NO_RESERVED_STD
export module std.sys.CSignal;
#else
export module stdlib.sys.CSignal;
#endif

export import :Constants;

/**
 * @namespace stdlib::sys
 * @brief Wrapper namespace for standard library system operations.
 */
export namespace stdlib::sys {
    using SigAtomic_t = std::sig_atomic_t;

    using std::signal;
    using std::raise;
}
