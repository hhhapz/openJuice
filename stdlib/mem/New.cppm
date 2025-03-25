/**
 * @file New.cppm
 * @brief Module file for standard library dynamic memory management operations.
 *
 * This file contains the implementation of the dynamic memory management operations in the standard library.
 */

module;

#include <new>

#ifdef NO_RESERVED_STD
export module std.mem.New;
#else
export module stdlib.mem.New;
#endif

/**
 * @namespace stdlib::mem
 * @brief Wrapper namespace for standard library memory operations.
 */
export namespace stdlib::mem {
    using AlignVal_t = std::align_val_t;

    using NewHandler = std::new_handler;

    using NoThrow_t = std::nothrow_t;
    using DestroyingDelete_t = std::destroying_delete_t;

    using BadAllocException = std::bad_alloc;
    using BadArrayNewLengthException = std::bad_array_new_length;

    using std::get_new_handler;
    using std::set_new_handler;
    
    using std::launder;
}
