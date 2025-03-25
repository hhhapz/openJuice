/**
 * @file CintTypesConstants.cppm
 * @brief Module file for constants of the standard library C-style integer formatting constant operations.
 *
 * This file contains the implementation of the constants of the C-style integer formatting constant operations in the standard library.
 */

#ifdef NO_RESERVED_STD
export module std.fmt.CIntTypes:Constants;
#else
export module stdlib.fmt.CIntTypes:Constants;
#endif

/**
 * @namespace stdlib::sys
 * @brief Wrapper namespace for standard library system operations.
 */
export namespace stdlib::sys {
    // Print format specifiers for 32-bit integers
    constexpr inline char PRId32[] = "d";      ///< Format specifier for printing int32_t as decimal
    constexpr inline char PRIdLEAST32[] = "d"; ///< Format specifier for printing int_least32_t as decimal
    constexpr inline char PRIdFAST32[] = "d";  ///< Format specifier for printing int_fast32_t as decimal
    constexpr inline char PRIi32[] = "i";      ///< Format specifier for printing int32_t as decimal with base indicator
    constexpr inline char PRIiLEAST32[] = "i"; ///< Format specifier for printing int_least32_t with base indicator
    constexpr inline char PRIiFAST32[] = "i";  ///< Format specifier for printing int_fast32_t with base indicator
    constexpr inline char PRIo32[] = "o";      ///< Format specifier for printing uint32_t as octal
    constexpr inline char PRIoLEAST32[] = "o"; ///< Format specifier for printing uint_least32_t as octal
    constexpr inline char PRIoFAST32[] = "o";  ///< Format specifier for printing uint_fast32_t as octal
    constexpr inline char PRIu32[] = "u";      ///< Format specifier for printing uint32_t as unsigned decimal
    constexpr inline char PRIuLEAST32[] = "u"; ///< Format specifier for printing uint_least32_t as unsigned decimal
    constexpr inline char PRIuFAST32[] = "u";  ///< Format specifier for printing uint_fast32_t as unsigned decimal
    constexpr inline char PRIx32[] = "x";      ///< Format specifier for printing uint32_t as lowercase hex
    constexpr inline char PRIxLEAST32[] = "x"; ///< Format specifier for printing uint_least32_t as lowercase hex
    constexpr inline char PRIxFAST32[] = "x";  ///< Format specifier for printing uint_fast32_t as lowercase hex
    constexpr inline char PRIX32[] = "X";      ///< Format specifier for printing uint32_t as uppercase hex
    constexpr inline char PRIXLEAST32[] = "X"; ///< Format specifier for printing uint_least32_t as uppercase hex
    constexpr inline char PRIXFAST32[] = "X";  ///< Format specifier for printing uint_fast32_t as uppercase hex
    
    // Scan format specifiers for 32-bit integers
    constexpr inline char SCNd32[] = "d";      ///< Format specifier for scanning int32_t as decimal
    constexpr inline char SCNdLEAST32[] = "d"; ///< Format specifier for scanning int_least32_t as decimal
    constexpr inline char SCNdFAST32[] = "d";  ///< Format specifier for scanning int_fast32_t as decimal
    constexpr inline char SCNi32[] = "i";      ///< Format specifier for scanning int32_t with auto base detection
    constexpr inline char SCNiLEAST32[] = "i"; ///< Format specifier for scanning int_least32_t with auto base detection
    constexpr inline char SCNiFAST32[] = "i";  ///< Format specifier for scanning int_fast32_t with auto base detection
    constexpr inline char SCNo32[] = "o";      ///< Format specifier for scanning uint32_t as octal
    constexpr inline char SCNoLEAST32[] = "o"; ///< Format specifier for scanning uint_least32_t as octal
    constexpr inline char SCNoFAST32[] = "o";  ///< Format specifier for scanning uint_fast32_t as octal
    constexpr inline char SCNu32[] = "u";      ///< Format specifier for scanning uint32_t as unsigned decimal
    constexpr inline char SCNuLEAST32[] = "u"; ///< Format specifier for scanning uint_least32_t as unsigned decimal
    constexpr inline char SCNuFAST32[] = "u";  ///< Format specifier for scanning uint_fast32_t as unsigned decimal
    constexpr inline char SCNx32[] = "x";      ///< Format specifier for scanning uint32_t as hex (both cases)
    constexpr inline char SCNxLEAST32[] = "x"; ///< Format specifier for scanning uint_least32_t as hex (both cases)
    constexpr inline char SCNxFAST32[] = "x";  ///< Format specifier for scanning uint_fast32_t as hex (both cases)
}
