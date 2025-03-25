/**
 * @file Buffer.cppm
 * @brief Module file for (experimental) standard library networking I/O context operations.
 *
 * This file contains the implementation of the (experimental) networking I/O context operations in the standard library.
 */


module;

#ifdef __GNUC__
#ifdef EXPERIMENTAL_STD
#include <experimental/io_context>
#endif
#endif

#ifdef NO_RESERVED_STD
export module std.net.IOContext;
#else
export module stdlib.net.IOContext;
#endif

/**
 * @namespace stdlib::net
 * @brief Wrapper namespace for (experimental) standard library networking operations.
 */
export namespace stdlib::net {
    #ifdef EXPERIMENTAL_STD
    using IOContext = std::experimental::net::io_context;
    using ExecutorType = std::experimental::net::io_context::executor_type;
    #endif
}
