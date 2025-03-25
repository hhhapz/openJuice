/**
 * @file StopToken.cppm
 * @brief Module file for standard library stop token operations.
 *
 * This file contains the implementation of the stop token operations in the standard library.
 */

module;

#include <stop_token>

#ifdef NO_RESERVED_STD
export module std.concurrency.StopToken;
#else
export module stdlib.concurrency.StopToken;
#endif

/**
 * @namespace stdlib::concurrency
 * @brief Wrapper namespace for standard library concurrency operations.
 */
export namespace stdlib::concurrency {
    using StopToken = std::stop_token;
    using StopSource = std::stop_source;

    template<typename Callback>
    using StopCallback = std::stop_callback<Callback>;

    using NoStopState_t = std::nostopstate_t;

    using std::swap;
}
