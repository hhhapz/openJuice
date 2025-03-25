/**
 * @file Buffer.cppm
 * @brief Module file for (experimental) standard library networking timer operations.
 *
 * This file contains the implementation of the (experimental) networking timer operations in the standard library.
 */


module;

#ifdef __GNUC__
#ifdef EXPERIMENTAL_STD
#include <experimental/timer>
#endif
#endif

#ifdef NO_RESERVED_STD
export module std.net.Timer;
#else
export module stdlib.net.Timer;
#endif

/**
 * @namespace stdlib::net
 * @brief Wrapper namespace for (experimental) standard library networking operations.
 */
export namespace stdlib::net {
    #ifdef EXPERIMENTAL_STD
    template<typename Clock>
    using WaitTraits = std::experimental::net::wait_traits<Clock>;

    template<typename Clock, typename _WaitTraits>
    using BasicWaitableTimer = std::experimental::net::basic_waitable_timer<Clock, _WaitTraits>;

    using SystemTimer = std::experimental::net::system_timer;
    using SteadyTimer = std::experimental::net::steady_timer;
    using HighResolutionTimer = std::experimental::net::high_resolution_timer;
    #endif
}
