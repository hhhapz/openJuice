/**
 * @file NDBM.cppm
 * @brief Module file for Unix NDBM database operations.
 *
 * This file contains the implementation of the Unix NDBM database operations from the POSIX libraries.
 */

module;

#ifdef __unix__
#include <ndbm.h>
#endif

#ifdef NO_RESERVED_STD
export module std.os.unix.NDBM;
#else
export module stdlib.os.unix.NDBM;
#endif

/**
 * @namespace stdlib::os::posix
 * @brief Wrapper namespace for Unix POSIX operations.
 */
export namespace stdlib::os::posix {
    #ifdef __unix__
    using ::dbm_open;
    using ::dbm_close;
    using ::dbm_fetch;
    using ::dbm_store;
    using ::dbm_delete;
    using ::dbm_firstkey;
    using ::dbm_nextkey;
    using ::dbm_error;
    using ::dbm_clearerr;
    using ::dbm_dirfno;
    using ::dbm_pagfno;
    using ::dbm_rdonly;
    #endif
}
