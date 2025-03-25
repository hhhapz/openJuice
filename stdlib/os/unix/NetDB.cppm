/**
 * @file NetDB.cppm
 * @brief Module file for Unix numeric address translation operations.
 *
 * This file contains the implementation of the Unix numeric address translation operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <netdb.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.NetDB;
#else
export module stdlib.os.unix.NetDB;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::herror;
    using ::hstrerror;

    using HostEnt = ::hostent;

    using ::sethostent;
    using ::endhostent;
    using ::gethostent;
    using ::gethostbyaddr;
    using ::gethostbyname;
    using ::gethostbyname2;
    using ::gethostent_r;
    using ::gethostbyaddr_r;
    using ::gethostbyname_r;
    using ::gethostbyname2_r;
    #endif
}
