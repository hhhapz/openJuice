/**
 * @file MemoryResource.cppm
 * @brief Module file for standard library memory resource operations.
 *
 * This file contains the implementation of the memory resource operations in the standard library.
 */

module;

#include <memory_resource>

#ifdef NO_RESERVED_STD
export module std.mem.MemoryResource;
#else
export module stdlib.mem.MemoryResource;
#endif

/**
 * @namespace stdlib::mem
 * @brief Wrapper namespace for standard library memory operations.
 */
export namespace stdlib::mem {
    /**
     * @namespace pmr
     * @brief Namespace for operations on polymorphic memory resources.
     */
    namespace pmr {
        template<typename T>
        using PolymorphicAllocator = std::pmr::polymorphic_allocator<T>;

        using MemoryResource = std::pmr::memory_resource;
        using PoolOptions = std::pmr::pool_options;
        using SynchronizedPoolResource = std::pmr::synchronized_pool_resource;
        using UnsynchronizedPoolResource = std::pmr::unsynchronized_pool_resource;
        using MonotoneBufferResource = std::pmr::monotonic_buffer_resource;

        using std::pmr::new_delete_resource;
        using std::pmr::null_memory_resource;
        using std::pmr::get_default_resource;
        using std::pmr::set_default_resource;
    }
}
