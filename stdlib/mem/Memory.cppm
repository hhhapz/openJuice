/**
 * @file Memory.cppm
 * @brief Module file for standard library memory operations.
 *
 * This file contains the implementation of the memory operations in the standard library.
 */

module;

#include <memory>

#ifdef NO_RESERVED_STD
export module std.mem.Memory;
#else
export module stdlib.mem.Memory;
#endif

/**
 * @namespace stdlib::mem
 * @brief Wrapper namespace for standard library memory operations.
 */
export namespace stdlib::mem {
    template<typename Ptr>
    using PointerTraits = std::pointer_traits<Ptr>;

    template<typename Ptr>
    using Allocator = std::allocator<Ptr>;

    template<typename Ptr>
    using AllocatorTraits = std::allocator_traits<Ptr>;

    template<typename Ptr, typename Alloc>
    using UsesAllocator = std::uses_allocator<Ptr, Alloc>;

    template<typename T>
    using UniquePtr = std::unique_ptr<T>;

    template<typename T>
    using SharedPtr = std::shared_ptr<T>;

    template<typename T>
    using WeakPtr = std::weak_ptr<T>;

    template<typename T>
    using OwnerLess = std::owner_less<T>;

    template<typename T>
    using EnableSharedFromThis = std::enable_shared_from_this<T>;

    template<typename T>
    using DefaultDelete = std::default_delete<T>;

    using std::hash;

    template<typename Smart, typename Pointer, typename... Args>
    using OutPtr_t = std::out_ptr_t<Smart, Pointer, Args...>;

    template<typename Smart, typename Pointer, typename... Args>
    using InOutPtr_t = std::inout_ptr_t<Smart, Pointer, Args...>;

    using BadWeakPointerException = std::bad_weak_ptr;

    using std::uses_allocator_construction_args;
    using std::make_obj_using_allocator;
    using std::uninitialized_construct_using_allocator;

    using std::to_address;
    using std::addressof;
    using std::align;
    using std::assume_aligned;

    using std::uninitialized_copy;
    using std::uninitialized_copy_n;
    using std::uninitialized_fill;
    using std::uninitialized_fill_n;
    using std::uninitialized_move;
    using std::uninitialized_move_n;
    using std::uninitialized_default_construct;
    using std::uninitialized_default_construct_n;
    using std::uninitialized_value_construct;
    using std::uninitialized_value_construct_n;
    using std::construct_at;
    using std::destroy_at;
    using std::destroy;
    using std::destroy_n;

    using std::make_unique;
    using std::make_unique_for_overwrite;
    using std::make_shared;
    using std::make_shared_for_overwrite;
    using std::allocate_shared;
    using std::allocate_shared_for_overwrite;
    using std::static_pointer_cast;
    using std::dynamic_pointer_cast;
    using std::const_pointer_cast;
    using std::reinterpret_pointer_cast;
    using std::get_deleter;

    using std::swap;

    using std::out_ptr;
    using std::inout_ptr;
}
