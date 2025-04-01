/**
 * @file Censor.cppm
 * @brief Implementation of the Censor class.
 *
 * This file contains the implementation of the Censor class, which is used to censor inappropriate words in chat messages.
 */

module;

#ifdef _MSC_VER
    #pragma warning(push)
    #pragma warning(disable: 4244)
    #pragma warning(disable: 4267)
#else
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wconversion"
    #pragma GCC diagnostic ignored "-Wsign-conversion"
#endif

#include <boost/regex.hpp>

#ifdef _MSC_VER
    #pragma warning(pop)
#else
    #pragma GCC diagnostic pop
#endif

export module chat.Chat:Censor;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.io;
import std.fmt;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.io;
import stdlib.fmt;
#endif

import engine.managers.GlobalSettings;
import engine.utility.EngineUtility;
import engine.utility.Exceptions;
import engine.utility.GameInfo;
import engine.utility.Language;

using namespace stdlib::collections;
using stdlib::io::IFStream;

using namespace exceptions;

/**
 * @class Censor
 * @brief Class for censoring inappropriate words in chat messages.
 * 
 * The Censor class is a singleton class that censors inappropriate words in chat messages based on a blacklist.
 */
export class Censor {
private:
    Vector<String> blacklist; ///< List of inappropriate words to censor.
    const String gameLanguageCode; ///< The language code currently being used by the game.
    char censorChar; ///< Character used for censoring.

    /**
     * @brief Private constructor to prevent instantiation.
     * @throws InvalidLanguageException if no valid language is found
     */
    Censor():
        gameLanguageCode{GlobalSettings::languageToString(GlobalSettings::getInstance().getLanguage())} {
        Language gameLanguage = GlobalSettings::getInstance().getLanguage();
        switch (gameLanguage) {
            case Language::English:
            case Language::Russian:
            case Language::Spanish:
            case Language::PortugueseBR:
                censorChar = '*';
                break;
            case Language::Japanese:
            case Language::SimplifiedChinese:
            case Language::TraditionalChinese:
            case Language::Korean:
                censorChar = '#';
                break;
            default:
                throw InvalidLanguageException("Invalid language code");
        }
        loadBlacklist(gameLanguage);
    }

    /**
     * @brief Load the blacklist for the specified language.
     * @param language The language for which to load the blacklist.
     * @throws InvalidLanguageException if no valid language is found
     */
    void loadBlacklist(Language language) {
        DebugLogger::getInstance().log("Loading blacklist for language of value {}", static_cast<u8>(language));
        String filename = fmt::format(RuntimePaths::PATH_BLACKLIST_FILE, gameLanguageCode);
        blacklist.clear();
        String word;
        IFStream file(filename);
        while (io::getline(file, word))
            if (!word.empty())
                blacklist.push_back(word);
    }

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    Censor(const Censor&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    Censor& operator=(const Censor&) = delete;
public:
    /**
     * @brief Get the singleton instance of Censor.
     * @return The singleton instance.
     */
    static Censor& getInstance() {
        static Censor instance;
        return instance;
    }

    /**
     * @brief Censor inappropriate words in a message.
     * @param message The message to censor.
     * @return The censored message.
     */
    String censorMessage(const String& message) const {
        String censoredMessage = message;
        for (const String& word: blacklist) {
            boost::regex pattern("\\b" + word + "\\b", boost::regex_constants::icase);
            String replacement(word.length(), censorChar);
            censoredMessage = boost::regex_replace(censoredMessage, pattern, replacement);
        }
        return censoredMessage;
    }
};