/**
 * @file Functional.cppm
 * @brief Module file for importing function objects from the standard library.
 *
 * This file contains the implementation of the function object operations in the standard library.
 */

module;

#include <functional>

#ifdef NO_RESERVED_STD
export module std.core.Functional;
#else
export module stdlib.core.Functional;
#endif

/**
 * @namespace stdlib
 * @brief Wrapper namespace for the standard library.
 */
export namespace stdlib {
    // template<typename R, typename... Args>
    // using Function = std::function<R(Args...)>;

    template<typename Signature>
    using Function = std::function<Signature>;

    // template<typename R, typename... Args>
    // using MoveOnlyFunction = std::move_only_function<R(Args...)>;

    template<typename Signature>
    using MoveOnlyFunction = std::move_only_function<Signature>;

    template<typename T>
    using ReferenceWrapper = std::reference_wrapper<T>;

    template<typename T>
    using UnwrapReference = std::unwrap_reference<T>;

    template<typename T>
    using UnwrapRefDecay = std::unwrap_ref_decay<T>;

    template<typename T>
    using IsBindExpression = std::is_bind_expression<T>;

    template<typename T>
    using IsPlaceholder = std::is_placeholder<T>;

    template<typename T>
    using Plus = std::plus<T>;

    template<typename T>
    using Minus = std::minus<T>;

    template<typename T>
    using Multiplies = std::multiplies<T>;

    template<typename T>
    using Divides = std::divides<T>;

    template<typename T>
    using Modulus = std::modulus<T>;

    template<typename T>
    using Negate = std::negate<T>;

    template<typename T>
    using EqualTo = std::equal_to<T>;

    template<typename T>
    using NotEqualTo = std::not_equal_to<T>;

    template<typename T>
    using Greater = std::greater<T>;

    template<typename T>
    using Less = std::less<T>;

    template<typename T>
    using GreaterEqual = std::greater_equal<T>;

    template<typename T>
    using LessEqual = std::less_equal<T>;

    using CompareThreeWay = std::compare_three_way;

    template<typename T>
    using LogicalAnd = std::logical_and<T>;

    template<typename T>
    using LogicalOr = std::logical_or<T>;

    template<typename T>
    using LogicalNot = std::logical_not<T>;

    template<typename T>
    using BitAnd = std::bit_and<T>;

    template<typename T>
    using BitOr = std::bit_or<T>;

    template<typename T>
    using BitXor = std::bit_xor<T>;

    template<typename T>
    using BitNot = std::bit_not<T>;

    using Identity = std::identity;

    template<typename ForwardIterator>
    using DefaultSearcher = std::default_searcher<ForwardIterator>;

    template<typename RandomIterator>
    using BoyerMooreSearcher = std::boyer_moore_searcher<RandomIterator>;

    template<typename RandomIterator>
    using BoyerMooreHorspoolSearcher = std::boyer_moore_horspool_searcher<RandomIterator>;

    using BadFunctionCallException = std::bad_function_call;

    using std::hash;

    /**
     * @brief Wrapper namespace for placeholder objects of the Functional namespace (up to 29).
     */
    namespace Placeholders {
        using std::placeholders::_1;
        using std::placeholders::_2;
        using std::placeholders::_3;
        using std::placeholders::_4;
        using std::placeholders::_5;
        using std::placeholders::_6;
        using std::placeholders::_7;
        using std::placeholders::_8;
        using std::placeholders::_9;
        using std::placeholders::_10;
        using std::placeholders::_11;
        using std::placeholders::_12;
        using std::placeholders::_13;
        using std::placeholders::_14;
        using std::placeholders::_15;
        using std::placeholders::_16;
        using std::placeholders::_17;
        using std::placeholders::_18;
        using std::placeholders::_19;
        using std::placeholders::_20;
        using std::placeholders::_21;
        using std::placeholders::_22;
        using std::placeholders::_23;
        using std::placeholders::_24;
        using std::placeholders::_25;
        using std::placeholders::_26;
        using std::placeholders::_27;
        using std::placeholders::_28;
        using std::placeholders::_29;
    }

    using std::bind_front;
    using std::bind;
    using std::ref;
    using std::cref;
    using std::invoke;
}
