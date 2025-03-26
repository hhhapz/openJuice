/**
 * @file Language.cppm
 * @brief Definition of the Language enum class.
 *
 * This file contains the definition of the Language enum class, which represents supported languages.
 */

module;

#include <format>

export module engine.utility.Language;

#ifdef NO_RESERVED_STD
import std.core;
import std.fmt;
import std.sys;
#else
import stdlib.core;
import stdlib.fmt;
import stdlib.sys;
#endif

using fmt::FormatContext, fmt::FormatParseContext;

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

// Must use std::formatter, not fmt::Formatter
template<>
struct std::formatter<Language> {
    constexpr auto parse(FormatParseContext& ctx) -> const char* {
        return ctx.begin();
    }

    auto format(const Language& lang, FormatContext& ctx) const {
        StringView name;
        switch (lang) {
            case Language::English:
                name = "English";
                break;
            case Language::Japanese:
                name = "Japanese";
                break;
            case Language::SimplifiedChinese:
                name = "Simplified Chinese";
                break;
            case Language::TraditionalChinese:
                name = "Traditional Chinese";
                break;
            case Language::Russian:
                name = "Russian";
                break;
            case Language::Korean:
                name = "Korean";
                break;
            case Language::Spanish:
                name = "Spanish";
                break;
            case Language::PortugueseBR:
                name = "Brazilian Portuguese";
                break;
            default:
                sys::unreachable();
        }
        return std::format_to(ctx.out(), "{}", name);
    }
};

export template struct std::formatter<Language>;