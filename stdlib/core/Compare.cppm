/**
 * @file Compare.cppm
 * @brief Module file for standard library comparison operations.
 *
 * This file contains the implementation of the comparison operations in the standard library.
 */

module;

#include <compare>

#ifdef NO_RESERVED_STD
export module std.core.Compare;
#else
export module stdlib.core.Compare;
#endif

/**
 * @namespace stdlib::compare
 * @brief Wrapper namespace for standard library comparison operations.
 */
export namespace stdlib::compare {
    template<typename T>
    concept ThreeWayComparable = std::three_way_comparable<T>;

    template<typename T, typename U>
    concept ThreeWayComparableWith = std::three_way_comparable_with<T, U>;

    using PartialOrdering = std::partial_ordering;
    using WeakOrdering = std::weak_ordering;
    using StrongOrdering = std::strong_ordering;

    template<typename... Ts>
    using CommonComparisonCategory = std::common_comparison_category<Ts...>;

    template<typename T>
    using CompareThreeWayResult = std::compare_three_way_result<T>;

    using CompareThreeWay = std::compare_three_way;

    using std::strong_ordering;
    using std::weak_ordering;
    using std::partial_ordering;
    using std::compare_strong_order_fallback;
    using std::compare_weak_order_fallback;
    using std::compare_partial_order_fallback;

    using std::is_eq;
    using std::is_neq;
    using std::is_lt;
    using std::is_lteq;
    using std::is_gt;
    using std::is_gteq;
}
