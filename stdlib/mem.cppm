/**
 * @file mem.cppm
 * @brief Module file for standard library memory operations.
 *
 * This file contains the imports for the memory operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.mem;
#else
export module stdlib.mem;
#endif

#ifdef NO_RESERVED_STD
export import std.mem.CStdLib;
export import std.mem.Memory;
export import std.mem.MemoryResource;
export import std.mem.New;
export import std.mem.ScopedAllocator;
#else
export import stdlib.mem.CStdLib;
export import stdlib.mem.Memory;
export import stdlib.mem.MemoryResource;
export import stdlib.mem.New;
export import stdlib.mem.ScopedAllocator;
#endif

export using namespace stdlib;
