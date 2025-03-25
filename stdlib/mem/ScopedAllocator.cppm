/**
 * @file ScopedAllocator.cppm
 * @brief Module file for standard library scoped allocator operations.
 *
 * This file contains the implementation of the scoped allocator operations in the standard library.
 */

module;

#include <scoped_allocator>

#ifdef NO_RESERVED_STD
export module std.mem.ScopedAllocator;
#else
export module stdlib.mem.ScopedAllocator;
#endif

/**
 * @namespace stdlib::mem
 * @brief Wrapper namespace for standard library memory operations.
 */
export namespace stdlib::mem {
    template<typename OuterAlloc, typename... InnerAllocs>
    using ScopedAllocatorAdaptor = std::scoped_allocator_adaptor<OuterAlloc, InnerAllocs...>;
}
