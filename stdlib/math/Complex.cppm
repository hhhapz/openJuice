/**
 * @file Complex.cppm
 * @brief Module file for standard library complex number operations.
 *
 * This file contains the implementation of the complex number operations in the standard library.
 */

module;

#include <complex>

#ifdef NO_RESERVED_STD
export module std.math.Complex;
#else
export module stdlib.math.Complex;
#endif

/**
 * @namespace stdlib::math
 * @brief Wrapper namespace for standard library mathematical operations.
 */
export namespace stdlib::math {
    template<typename T>
    using Complex = std::complex<T>;

    using std::operator+;
    using std::operator-;
    using std::operator*;
    using std::operator/;
    using std::operator==;
    using std::operator<<;
    using std::operator>>;

    using std::real;
    using std::imag;
    using std::abs;
    using std::arg;
    using std::norm;
    using std::conj;
    using std::proj;
    using std::polar;

    using std::exp;
    using std::log;
    using std::log10;
    using std::pow;
    using std::sqrt;
    using std::sin;
    using std::cos;
    using std::tan;
    using std::asin;
    using std::acos;
    using std::atan;
    using std::sinh;
    using std::cosh;
    using std::tanh;
    using std::asinh;
    using std::acosh;
    using std::atanh;

    using std::operator""if;
    using std::operator""i;
    using std::operator""il;
}
