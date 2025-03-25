/**
 * @file Language.cppm
 * @brief Definition of the Language enum class.
 *
 * This file contains the definition of the Language enum class, which represents supported languages.
 */

export module engine.utility.Language;

/**
 * @enum Language 
 * @brief Enum class for supported languages.
 */
export enum class Language {
    English, ///< English language.
    Japanese, ///< Japanese language.
    SimplifiedChinese, ///< Simplified Chinese language.
    TraditionalChinese, ///< Traditional Chinese language.
    Russian, ///< Russian language.
    Korean, ///< Korean language.
    Spanish, ///< Spanish language.
    PortugueseBR ///< Brazilian Portuguese language.
};