/**
 * @file OStream.cppm
 * @brief Module file for standard library output stream operations.
 *
 * This file contains the implementation of the output stream operations in the standard library.
 */

module;

#include <ostream>

#ifdef NO_RESERVED_STD
export module std.io.OStream;
#else
export module stdlib.io.OStream;
#endif

/**
 * @namespace stdlib::io
 * @brief Wrapper namespace for standard library input/output operations.
 */
export namespace stdlib::io {
    using OStream = std::ostream;
    using WOStream = std::wostream;

    using std::endl;
    using std::ends;
    using std::flush;
    using std::emit_on_flush;
    using std::noemit_on_flush;
    using std::flush_emit;
}
