/**
 * @file SyncStream.cppm
 * @brief Module file for standard library syncstream operations.
 *
 * This file contains the implementation of the syncstream operations in the standard library.
 */

module;

#include <syncstream>

#ifdef NO_RESERVED_STD
export module std.io.SyncStream;
#else
export module stdlib.io.SyncStream;
#endif

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library IO operations.
 */
export namespace stdlib::io {
    template<typename CharT>
    using BasicSyncBuf = std::basic_syncbuf<CharT>;

    template<typename CharT>
    using BasicOSyncStream = std::basic_osyncstream<CharT>;

    using SyncBuf = std::syncbuf;
    using WSyncBuf = std::wsyncbuf;
    using OSyncStream = std::osyncstream;
    using WOSyncStream = std::wosyncstream;

    using std::swap;
}
