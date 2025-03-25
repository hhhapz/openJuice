/**
 * @file TelNet.cppm
 * @brief Module file for Unix ARPA operations.
 *
 * This file contains the implementation of the Unix ARPA operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#define TELOPTS

#include <arpa/telnet.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.arpa.TelNet;
#else
export module stdlib.os.unix.arpa.TelNet;
#endif

/**
 * @namespace stdlib::os::posix::arpa
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::arpa {
    #ifdef __unix__
    using ::telcmds;
    using ::telopts;
    using ::slc_names;
    using ::authtype_names;
    using ::encrypt_names;
    using ::enctype_names;
    #endif
}
