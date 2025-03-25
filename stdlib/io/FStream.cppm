/**
 * @file FStream.cppm
 * @brief Module file for standard library file stream operations.
 *
 * This file contains the implementation of the file stream operations in the standard library.
 */

module;

#include <fstream>

#ifdef NO_RESERVED_STD
export module std.io.FStream;
#else
export module stdlib.io.FStream;
#endif

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library input/output operations.
 */
export namespace stdlib::io {
    using FileBuf = std::filebuf;
    using WFileBuf = std::wfilebuf;
    using IFStream = std::ifstream;
    using WIFStream = std::wifstream;
    using OFStream = std::ofstream;
    using WOFStream = std::wofstream;
    using FStream = std::fstream;
    using WFStream = std::wfstream;

    using std::operator>>;
    using std::operator<<;
}
