/**
 * @file fs.cppm
 * @brief Module file for standard library file system operations.
 *
 * This file contains the imports for the file system operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.fs;
#else
export module stdlib.fs;
#endif

#ifdef NO_RESERVED_STD
export import std.fs.FileSystem;
#else
export import stdlib.fs.FileSystem;
#endif

export using namespace stdlib;
