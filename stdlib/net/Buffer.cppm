/**
 * @file Buffer.cppm
 * @brief Module file for (experimental) standard library networking buffer operations.
 *
 * This file contains the implementation of the (experimental) networking buffer operations in the standard library.
 */

module;

#ifdef __GNUC__
#ifdef EXPERIMENTAL_STD
#include <experimental/buffer>
#endif
#endif

#ifdef NO_RESERVED_STD
export module std.net.Buffer;
#else
export module stdlib.net.Buffer;
#endif

/**
 * @namespace stdlib::net
 * @brief Wrapper namespace for (experimental) standard library networking operations.
 */
export namespace stdlib::net {
    #ifdef EXPERIMENTAL_STD
    using ConstBuffer = std::experimental::net::const_buffer;
    using MutableBuffer = std::experimental::net::mutable_buffer;

    template<typename T, typename Allocator>
    using DynamicVectorBuffer = std::experimental::net::dynamic_vector_buffer<T, Allocator>;

    template<typename CharT, typename Traits, typename Allocator>
    using DynamicStringBuffer = std::experimental::net::dynamic_string_buffer<CharT, Traits, Allocator>;

    using TransferAll = std::experimental::net::transfer_all;
    using TransferAtLeast = std::experimental::net::transfer_at_least;
    using TransferExactly = std::experimental::net::transfer_exactly;
    #endif
}
