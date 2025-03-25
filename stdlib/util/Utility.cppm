/**
 * @file CStdLib.cppm
 * @brief Module file for standard library utility operations.
 *
 * This file contains the implementation of the utility operations in the standard library.
 */

module;

#include <utility>

#ifdef NO_RESERVED_STD
export module std.util.Utility;
#else
export module stdlib.util.Utility;
#endif

/**
 * @namespace stdlib::util
 * @brief Wrapper namespace for standard library utility operations.
 */
export namespace stdlib::util {
    using std::swap;
    using std::exchange;
    using std::forward;
    using std::forward_like;
    using std::move;
    using std::move_if_noexcept;
    using std::as_const;
    using std::declval;
    using std::to_underlying;
    using std::cmp_equal;
    using std::cmp_not_equal;
    using std::cmp_less;
    using std::cmp_greater;
    using std::cmp_less_equal;
    using std::cmp_greater_equal;
    using std::in_range;
}
