/**
 * @file Atomic.cppm
 * @brief Module file for standard library atomic operations.
 *
 * This file contains the implementation of the atomic operations in the standard library.
 */

module;

#include <atomic>

#ifdef NO_RESERVED_STD
export module std.concurrency.Atomic;
#else
export module stdlib.concurrency.Atomic;
#endif

/**
 * @namespace stdlib::concurrency
 * @brief Wrapper namespace for standard library concurrency operations.
 */
export namespace stdlib::concurrency {
    // Atomic template class
    template<typename T>
    using Atomic = std::atomic<T>;
    
    // Atomic reference template class
    template<typename T>
    using AtomicRef = std::atomic_ref<T>;
    
    // Memory order enum
    using MemoryOrder = std::memory_order;
    
    // Memory order constants
    using std::memory_order_relaxed;
    using std::memory_order_consume;
    using std::memory_order_acquire;
    using std::memory_order_release;
    using std::memory_order_acq_rel;
    using std::memory_order_seq_cst;
    
    // Atomic flag
    using AtomicFlag = std::atomic_flag;
    
    // Basic atomic typedefs
    using AtomicBool = std::atomic_bool;
    using AtomicChar = std::atomic_char;
    using AtomicSChar = std::atomic_schar;
    using AtomicUChar = std::atomic_uchar;
    using AtomicShort = std::atomic_short;
    using AtomicUShort = std::atomic_ushort;
    using AtomicInt = std::atomic_int;
    using AtomicUInt = std::atomic_uint;
    using AtomicLong = std::atomic_long;
    using AtomicULong = std::atomic_ulong;
    using AtomicLLong = std::atomic_llong;
    using AtomicULLong = std::atomic_ullong;
    using AtomicChar8_t = std::atomic_char8_t;
    using AtomicChar16_t = std::atomic_char16_t;
    using AtomicChar32_t = std::atomic_char32_t;
    using AtomicWChar_t = std::atomic_wchar_t;
    
    // Integer type atomics
    using AtomicInt8_t = std::atomic_int8_t;
    using AtomicUint8_t = std::atomic_uint8_t;
    using AtomicInt16_t = std::atomic_int16_t;
    using AtomicUint16_t = std::atomic_uint16_t;
    using AtomicInt32_t = std::atomic_int32_t;
    using AtomicUint32_t = std::atomic_uint32_t;
    using AtomicInt64_t = std::atomic_int64_t;
    using AtomicUint64_t = std::atomic_uint64_t;
    
    // Least/fast atomic integer types
    using AtomicIntLeast8_t = std::atomic_int_least8_t;
    using AtomicUintLeast8_t = std::atomic_uint_least8_t;
    using AtomicIntLeast16_t = std::atomic_int_least16_t;
    using AtomicUintLeast16_t = std::atomic_uint_least16_t;
    using AtomicIntLeast32_t = std::atomic_int_least32_t;
    using AtomicUintLeast32_t = std::atomic_uint_least32_t;
    using AtomicIntLeast64_t = std::atomic_int_least64_t;
    using AtomicUintLeast64_t = std::atomic_uint_least64_t;
    
    using AtomicIntFast8_t = std::atomic_int_fast8_t;
    using AtomicUintFast8_t = std::atomic_uint_fast8_t;
    using AtomicIntFast16_t = std::atomic_int_fast16_t;
    using AtomicUintFast16_t = std::atomic_uint_fast16_t;
    using AtomicIntFast32_t = std::atomic_int_fast32_t;
    using AtomicUintFast32_t = std::atomic_uint_fast32_t;
    using AtomicIntFast64_t = std::atomic_int_fast64_t;
    using AtomicUintFast64_t = std::atomic_uint_fast64_t;
    
    // Other atomic integer types
    using AtomicIntptr_t = std::atomic_intptr_t;
    using AtomicUintptr_t = std::atomic_uintptr_t;
    using AtomicSize_t = std::atomic_size_t;
    using AtomicPtrdiff_t = std::atomic_ptrdiff_t;
    using AtomicIntmax_t = std::atomic_intmax_t;
    using AtomicUintmax_t = std::atomic_uintmax_t;
    
    // C++20 lock-free type aliases
    using AtomicSignedLockFree = std::atomic_signed_lock_free;
    using AtomicUnsignedLockFree = std::atomic_unsigned_lock_free;
    
    // Atomic flag functions
    using std::atomic_flag_test_and_set;
    using std::atomic_flag_test_and_set_explicit;
    using std::atomic_flag_clear;
    using std::atomic_flag_clear_explicit;
    using std::atomic_flag_test;
    using std::atomic_flag_test_explicit;

    using std::atomic_flag_wait;
    using std::atomic_flag_wait_explicit;
    using std::atomic_flag_notify_one;
    using std::atomic_flag_notify_all;
    using std::atomic_wait;
    using std::atomic_wait_explicit;
    using std::atomic_notify_one;
    using std::atomic_notify_all;
    
    // Atomic operations
    using std::atomic_is_lock_free;
    using std::atomic_init;
    using std::atomic_store;
    using std::atomic_store_explicit;
    using std::atomic_load;
    using std::atomic_load_explicit;
    using std::atomic_exchange;
    using std::atomic_exchange_explicit;
    using std::atomic_compare_exchange_weak;
    using std::atomic_compare_exchange_weak_explicit;
    using std::atomic_compare_exchange_strong;
    using std::atomic_compare_exchange_strong_explicit;
    
    // Atomic arithmetic operations
    using std::atomic_fetch_add;
    using std::atomic_fetch_add_explicit;
    using std::atomic_fetch_sub;
    using std::atomic_fetch_sub_explicit;
    using std::atomic_fetch_and;
    using std::atomic_fetch_and_explicit;
    using std::atomic_fetch_or;
    using std::atomic_fetch_or_explicit;
    using std::atomic_fetch_xor;
    using std::atomic_fetch_xor_explicit;
    
    // Fence functions
    using std::atomic_thread_fence;
    using std::atomic_signal_fence;
    
    // Hash function
    using std::hash;
    using std::swap;
}
