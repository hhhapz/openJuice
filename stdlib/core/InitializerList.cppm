/**
 * @file InitializerList.cppm
 * @brief Module file for importing the InitializerList class from the standard library.
 * 
 * This file exports the InitializerList class operations in the standard library.
 */

module;

#include <initializer_list>

#ifdef NO_RESERVED_STD
export module std.core.InitializerList;
#else
export module stdlib.core.InitializerList;
#endif

/**
 * @namespace stdlib
 * @brief Wrapper namespace for the standard library.
 */
export namespace stdlib {
    template<typename T>
    using InitializerList = std::initializer_list<T>;

    using std::begin;
    using std::end;
}