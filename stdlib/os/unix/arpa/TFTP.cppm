/**
 * @file TFTP.cppm
 * @brief Module file for Unix ARPA operations.
 *
 * This file contains the implementation of the Unix ARPA operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <arpa/tftp.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.arpa.TFTP;
#else
export module stdlib.os.unix.arpa.TFTP;
#endif

/**
 * @namespace stdlib::os::posix::arpa
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix::arpa {
    #ifdef __unix__
    using TFTPHdr = ::tftphdr;
    #endif
}
