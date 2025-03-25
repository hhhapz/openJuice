/**
 * @file Numbers.cppm
 * @brief Module file for standard library mathematical constants.
 *
 * This file contains the implementation of the mathematical constants in the standard library.
 */

module;

#include <numbers>

#ifdef NO_RESERVED_STD
export module std.math.Numbers;
#else
export module stdlib.math.Numbers;
#endif

/**
 * @namespace stdlib::math
 * @brief Wrapper namespace for standard library mathematical operations.
 */
export namespace stdlib::math {
    /**
     * @namespace stdlib::numbers
     * @brief Wrapper namespace for standard library numerical constants (for compatibility).
     */
    inline namespace numbers {
        constexpr inline double E = std::numbers::e; ///< e

        constexpr inline double LOG_2_E = std::numbers::log2e; ///< log_2 e

        constexpr inline double LOG_10_E = std::numbers::log10e; ///< log_10 e

        constexpr inline double PI = std::numbers::pi; ///< pi

        constexpr inline double INV_PI = std::numbers::inv_pi; ///< 1/pi

        constexpr inline double INV_SQRT_PI = std::numbers::inv_sqrtpi; ///< 1/sqrt(pi)

        constexpr inline double LN2 = std::numbers::ln2; ///< log_e 2

        constexpr inline double LN10 = std::numbers::ln10; ///< log_e 10

        constexpr inline double SQRT2 = std::numbers::sqrt2; ///< sqrt(2)

        constexpr inline double SQRT3 = std::numbers::sqrt3; ///< sqrt(3)

        constexpr inline double INV_SQRT3 = std::numbers::inv_sqrt3; ///< 1/sqrt(3)

        constexpr inline double E_GAMMA = std::numbers::egamma; ///< Euler-Mascheroni constant

        constexpr inline double PHI = std::numbers::phi; ///< Golden ratio (1+sqrt(5))/2
    }
}

/**
 * @namespace stdlib::numbers
 * @brief Wrapper namespace for standard library numerical constants (for compatibility).
 */
export namespace stdlib::numbers {
    constexpr inline double E = std::numbers::e; ///< e

    constexpr inline double LOG_2_E = std::numbers::log2e; ///< log_2 e

    constexpr inline double LOG_10_E = std::numbers::log10e; ///< log_10 e

    constexpr inline double PI = std::numbers::pi; ///< pi

    constexpr inline double INV_PI = std::numbers::inv_pi; ///< 1/pi

    constexpr inline double INV_SQRT_PI = std::numbers::inv_sqrtpi; ///< 1/sqrt(pi)

    constexpr inline double LN2 = std::numbers::ln2; ///< log_e 2

    constexpr inline double LN10 = std::numbers::ln10; ///< log_e 10

    constexpr inline double SQRT2 = std::numbers::sqrt2; ///< sqrt(2)

    constexpr inline double SQRT3 = std::numbers::sqrt3; ///< sqrt(3)

    constexpr inline double INV_SQRT3 = std::numbers::inv_sqrt3; ///< 1/sqrt(3)

    constexpr inline double E_GAMMA = std::numbers::egamma; ///< Euler-Mascheroni constant

    constexpr inline double PHI = std::numbers::phi; ///< Golden ratio (1+sqrt(5))/2
}
