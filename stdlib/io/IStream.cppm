/**
 * @file IStream.cppm
 * @brief Module file for standard library input stream operations.
 *
 * This file contains the implementation of the input stream operations in the standard library.
 */

module;

#include <istream>

#ifdef NO_RESERVED_STD
export module std.io.IStream;
#else
export module stdlib.io.IStream;
#endif

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library input/output operations.
 */
export namespace stdlib::io {
    using IStream = std::istream;
    using WIStream = std::wistream;
    using IOStream = std::iostream;
    using WIOStream = std::wiostream;
}
