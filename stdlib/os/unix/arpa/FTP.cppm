/**
 * @file FTP.cppm
 * @brief Module file for Unix ARPA operations.
 *
 * This file contains the implementation of the Unix ARPA operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#define FTP_NAMES

#include <arpa/ftp.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.arpa.FTP;
#else
export module stdlib.os.unix.arpa.FTP;
#endif

/**
 * @namespace stdlib::os::posix::arpa
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::arpa {
    #ifdef __unix__
    using ::typenames;
    using ::formnames;
    using ::strunames;
    using ::modenames;
    #endif
}
