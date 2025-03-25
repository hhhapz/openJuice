/**
 * @file Ratio.cppm
 * @brief Module file for standard library ratio operations.
 *
 * This file contains the implementation of the ratio operations in the standard library.
 */

module;

#include <ratio>

#ifdef NO_RESERVED_STD
export module std.math.Ratio;
#else
export module stdlib.math.Ratio;
#endif

/**
 * @namespace stdlib::ratio
 * @brief Wrapper namespace for standard library ratio operations.
 */
export namespace stdlib::ratio {
    template<std::intmax_t Num>
    using Ratio = std::ratio<Num>;

    template<typename R1, typename R2>
    using RatioAdd = std::ratio_add<R1, R2>;

    template<typename R1, typename R2>
    using RatioSubtract = std::ratio_subtract<R1, R2>;

    template<typename R1, typename R2>
    using RatioMultiply = std::ratio_multiply<R1, R2>;

    template<typename R1, typename R2>
    using RatioDivide = std::ratio_divide<R1, R2>;

    template<typename R1, typename R2>
    using RatioEqual = std::ratio_equal<R1, R2>;

    template<typename R1, typename R2>
    using RatioNotEqual = std::ratio_not_equal<R1, R2>;

    template<typename R1, typename R2>
    using RatioLess = std::ratio_less<R1, R2>;

    template<typename R1, typename R2>
    using RatioLessEqual = std::ratio_less_equal<R1, R2>;

    template<typename R1, typename R2>
    using RatioGreater = std::ratio_greater<R1, R2>;

    template<typename R1, typename R2>
    using RatioGreaterEqual = std::ratio_greater_equal<R1, R2>;

    using std::atto;
    using std::femto;
    using std::pico;
    using std::nano;
    using std::micro;
    using std::milli;
    using std::centi;
    using std::deci;
    using std::deca;
    using std::hecto;
    using std::kilo;
    using std::mega;
    using std::giga;
    using std::tera;
    using std::peta;
    using std::exa;
}
