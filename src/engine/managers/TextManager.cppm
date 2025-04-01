/**
 * @file TextManager.cppm
 * @brief Module file for managing parsing text from files.
 *
 * This file contains the implementation of the TextManager class.
 */
module;

#include <string>

export module engine.managers.TextManager;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.io;
import std.fmt;
import std.sys;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.io;
import stdlib.fmt;
import stdlib.sys;
#endif

import engine.managers.GlobalSettings;
import engine.utility.EngineUtility;
import engine.utility.GameInfo;
import engine.utility.Exceptions;

using namespace stdlib::collections;
using stdlib::io::IFStream;
using stdlib::io::IOSBaseException;

using namespace exceptions;

/**
 * @class TextManager
 * @brief Class for loading localisation and game initialisation.
 */
export class TextManager {
private:
    const String gameLanguageCode; ///< The language code currently being used by the game.

    static constexpr String EMPTY_STRING = ""; ///< The empty string.

    static constexpr String COMMENT_PREFIX = "//"; ///< A comment prefix used in the localisation files.
    static constexpr String EOF_MARKER = "[EOF]"; ///< A marker used to denote the end of the file in the localisation files.

    UnorderedMap<String, String> cardNames; ///< A dictionary of all card names.
    UnorderedMap<String, String> cardDescriptions; ///< A dictionary of all card descriptions.
    UnorderedMap<String, String> cardFlavours; ///< A dictionary of all card flavour texts.
    UnorderedMap<String, String> cardArtistNames; ///< A dictionary of all card artist names.
    UnorderedMap<String, String> fieldNames; ///< A dictionary of all field names.
    UnorderedMap<String, String> gameMessages; ///< A dictionary of all game messages.
    UnorderedMap<String, String> gameNormaTexts; ///< A dictionary of all messages issued during norma.
    UnorderedMap<String, String> gameSystemTexts; ///< A dictionary of all game system texts.
    UnorderedMap<String, String> menuScreenTexts; ///< A dictionary of all menu screen texts.
    UnorderedMap<String, String> resultTexts; ///< A dictionary of all result screen texts.
    UnorderedMap<String, String> unitNames; ///< A dictionary of all unit names.
    UnorderedMap<String, String> unitDescriptions; ///< A dictionary of all unit descriptions.
    UnorderedMap<String, String> voiceActorNames; ///< A dictionary of all voice actor names.

    /**
     * @brief Default constructor.
     */
    TextManager():
        gameLanguageCode{GlobalSettings::languageToString(GlobalSettings::getInstance().getLanguage())} {
        initialiseContents();
    }

    /**
     * @brief Destroy the TextManager object
     */
    ~TextManager() {
        cleanup();
    }

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    TextManager(const TextManager&) = delete;
 
    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    TextManager& operator=(const TextManager&) = delete;

    /**
     * @brief Parses a simple format file where values follow directly after keys.
     *
     * @param filePath Path to the file.
     * @param targetMap The map to populate with key-value pairs.
     * @throws IOSBaseException (std::ios_base::failure) if there is an issue opening the file
     */
    void parseSimpleFormatFile(const String& filePath, UnorderedMap<String, String>& targetMap) {
        IFStream file(filePath);
        if (!file.is_open())
            throw IOSBaseException(fmt::format("Failed to open file: {}", filePath));
        
        String line;
        String currentKey;
        bool expectingValue = false;
        
        while (io::getline(file, line)) {
            if (line.empty() || line.substr(0, 2) == COMMENT_PREFIX || line == EOF_MARKER)
                continue;
            
            if (line[0] == '<' && line[line.length() - 1] == '>') {
                currentKey = engineutility::strings::trimString(line.substr(1, line.length() - 2));
                expectingValue = true;
            } else if (expectingValue) {
                targetMap[currentKey] = line;
                expectingValue = false;
            }
        }
    }

    /**
     * @brief Parses the cards file and populates card-related maps.
     *
     * @param filePath Path to the cards file.
     * @throws IOSBaseException (std::ios_base::failure) if there is an issue opening the file
     */
    void parseCardsFile(const String& filePath) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Parsing cards file: {}", filePath);
        #endif
        
        IFStream file(filePath);
        if (!file.is_open())
            throw IOSBaseException("Failed to open cards file!");
        
        String line;
        String currentKey;
        String currentName;
        String currentDescription;
        String currentFlavor;
        
        while (io::getline(file, line)) {
            if (line.empty() || line.substr(0, 2) == COMMENT_PREFIX || line == EOF_MARKER)
                continue;
            
            if (line[0] == '<' && line[line.length() - 1] == '>') {
                if (!currentKey.empty()) {

                    cardDescriptions[currentKey] = currentDescription;
                    cardFlavours[currentKey] = currentFlavor;
                }
                currentKey = engineutility::strings::trimString(line.substr(1, line.length() - 2));
                currentName = "";
                currentDescription = "";
                currentFlavor = "";
            } else if (line.substr(0, 5) == "name=") {
                currentName = line.substr(5);
            } else if (line.substr(0, 6) == "descr=") {
                currentDescription = line.substr(6);
            } else if (line.substr(0, 7) == "flavor=") {
                currentFlavor = line.substr(7);
            }
        }
        
        if (!currentKey.empty()) {
            cardNames[currentKey] = currentName;
            cardDescriptions[currentKey] = currentDescription;
            cardFlavours[currentKey] = currentFlavor;
        }
    }

    /**
     * @brief Parses the card artist names file and populates the cardArtistNames map.
     *
     * @param filePath Path to the card artist names file.
     */
    inline void parseCardArtistNamesFile(const String& filePath) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Parsing card artist names file: {}", filePath);
        #endif

        parseSimpleFormatFile(filePath, cardArtistNames);
    }

    /**
     * @brief Parses the field names file and populates the fieldNames map.
     *
     * @param filePath Path to the field names file.
     */
    inline void parseFieldNamesFile(const String& filePath) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Parsing field names file: {}", filePath);
        #endif

        parseSimpleFormatFile(filePath, fieldNames);
    }

    /**
     * @brief Parses the game messages file and populates the gameMessages map.
     *
     * @param filePath Path to the game messages file.
     */
    inline void parseGameMessagesFile(const String& filePath) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Parsing game messages file: {}", filePath);
        #endif

        parseSimpleFormatFile(filePath, gameMessages);
    }

    /**
     * @brief Parses the game norma file and populates the gameNormaTexts map.
     *
     * @param filePath Path to the game norma file.
     */
    inline void parseGameNormaFile(const String& filePath) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Parsing game norma texts file: {}", filePath);
        #endif

        parseSimpleFormatFile(filePath, gameNormaTexts);
    }

    /**
     * @brief Parses the game system file and populates the gameSystemTexts map.
     *
     * @param filePath Path to the game system file.
     */
    inline void parseGameSystemFile(const String& filePath) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Parsing game system texts file: {}", filePath);
        #endif

        parseSimpleFormatFile(filePath, gameSystemTexts);
    }

    /**
     * @brief Parses the menu screens file and populates the menuScreenTexts map.
     *
     * @param filePath Path to the menu screens file.
     */
    inline void parseMenuScreensFile(const String& filePath) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Parsing menu screens texts file: {}", filePath);
        #endif
            
        parseSimpleFormatFile(filePath, menuScreenTexts);
    }

    /**
     * @brief Parses the result file and populates the resultTexts map.
     *
     * @param filePath Path to the result file.
     */
    inline void parseResultFile(const String& filePath) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Parsing result texts file: {}", filePath);
        #endif

        parseSimpleFormatFile(filePath, resultTexts);
    }

    /**
     * @brief Parses the units file and populates the unitNames map.
     *
     * @param filePath Path to the units file.
     * @throws IOSBaseException (std::ios_base::failure) if there is an issue opening the file
     */
     void parseUnitsFile(const String& filePath) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Parsing units file: {}", filePath);
        #endif

        IFStream file(filePath);
        if (!file.is_open())
            throw IOSBaseException(fmt::format("Failed to open units file!"));
        
        String line;
        String currentKey;
        String currentName;
        String currentDescription;
        
        while (io::getline(file, line)) {
            if (line.empty() || line.substr(0, 2) == COMMENT_PREFIX || line == EOF_MARKER)
                continue;
            
            if (line[0] == '<' && line[line.length() - 1] == '>') {
                if (!currentKey.empty() && !currentName.empty()) 
                    unitNames[currentKey] = currentName;
                currentKey = engineutility::strings::trimString(line.substr(1, line.length() - 2));
                currentName = "";
                currentDescription = "";
            } else if (line.substr(0, 5) == "name=") {
                currentName = line.substr(5);
            } else if (line.substr(0, 6) == "descr=") {
                currentDescription = line.substr(6);
            }
        }
        
        if (!currentKey.empty() && !currentName.empty()) {
            unitNames[currentKey] = currentName;
            unitDescriptions[currentKey] = currentDescription;
        }
    }

    /**
     * @brief Parses the voice actor names file and populates the voiceActorNames map.
     *
     * @param filePath Path to the voice actor names file.
     */
     inline void parseVoiceActorNamesFile(const String& filePath) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Parsing voice actor names file: {}", filePath);
        #endif

        parseSimpleFormatFile(filePath, voiceActorNames);
    }

    /**
     * @brief Initialises all text maps by parsing their respective files.
     */
    void initialiseContents() {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Now loading localisation contents");
        #endif

        parseCardsFile(fmt::format(AssetPaths::PATH_CARDS_FILE, gameLanguageCode));
        parseCardsFile(fmt::format(AssetPaths::PATH_CARDS_2_FILE, gameLanguageCode));
        parseCardArtistNamesFile(fmt::format(AssetPaths::PATH_CARDARTISTS_FILE, gameLanguageCode));
        parseFieldNamesFile(fmt::format(AssetPaths::PATH_FIELDNAMES_FILE, gameLanguageCode));
        parseGameMessagesFile(fmt::format(AssetPaths::PATH_GAME_MESSAGE_FILE, gameLanguageCode));
        parseGameNormaFile(fmt::format(AssetPaths::PATH_GAME_NORMA_FILE, gameLanguageCode));
        parseGameSystemFile(fmt::format(AssetPaths::PATH_GAME_SYSTEM_FILE, gameLanguageCode));
        parseMenuScreensFile(fmt::format(AssetPaths::PATH_MENUSCREENS_FILE, gameLanguageCode));
        parseResultFile(fmt::format(AssetPaths::PATH_RESULT_FILE, gameLanguageCode));
        parseUnitsFile(fmt::format(AssetPaths::PATH_UNITS_FILE, gameLanguageCode));
        parseVoiceActorNamesFile(fmt::format(AssetPaths::PATH_VOICEACTORS_FILE, gameLanguageCode));

        #ifndef NDEBUG
        DebugLogger::getInstance().log("Loading localisation complete!");
        #endif
    }

    /**
     * @brief Clears all localisation dictionaries, to be performed at cleanup.
     */
    void cleanup() {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Now cleaning localisation contents");
        #endif

        cardNames.clear();
        cardDescriptions.clear();
        cardFlavours.clear();
        cardArtistNames.clear();
        fieldNames.clear();
        gameMessages.clear();
        gameNormaTexts.clear();
        gameSystemTexts.clear();
        menuScreenTexts.clear();
        resultTexts.clear();
        unitNames.clear();
        unitDescriptions.clear();
        voiceActorNames.clear();

        #ifndef NDEBUG
        DebugLogger::getInstance().log("Cleaning localisation complete!");
        #endif
    }
public:
    /**
     * @brief Gets the singleton instance of TextManager.
     *
     * @return Reference to the singleton instance.
     */
    static TextManager& getInstance() {
        static TextManager instance;
        return instance;
    }

    /**
     * @brief Gets a card name by key.
     *
     * @param key The lookup key.
     * @return Reference to the name
     * @throws InvalidKeyException if the key does not exist
     */
    const String& getCardName(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = cardNames.find(key);
        if (it != cardNames.end()) 
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a card description by key.
     *
     * @param key The lookup key.
     * @return Reference to the description.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getCardDescription(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = cardDescriptions.find(key);
        if (it != cardDescriptions.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a card flavour text by key.
     *
     * @param key The lookup key.
     * @return Reference to the flavour text.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getCardFlavour(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = cardFlavours.find(key);
        if (it != cardFlavours.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a card artist name by key.
     *
     * @param key The lookup key.
     * @return Reference to the card artist name.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getCardArtistName(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = cardArtistNames.find(key);
        if (it != cardArtistNames.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a field name by key.
     *
     * @param key The lookup key.
     * @return Reference to the field name.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getFieldName(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = fieldNames.find(key);
        if (it != fieldNames.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a game message by key.
     *
     * @param key The lookup key.
     * @return Reference to the game message.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getGameMessage(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = gameMessages.find(key);
        if (it != gameMessages.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a norma text by key.
     *
     * @param key The lookup key.
     * @return Reference to the norma text.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getGameNormaText(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = gameNormaTexts.find(key);
        if (it != gameNormaTexts.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a game system text by key.
     *
     * @param key The lookup key.
     * @return Reference to the game system text.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getGameSystemText(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = gameSystemTexts.find(key);
        if (it != gameSystemTexts.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a menu screen text by key.
     *
     * @param key The lookup key.
     * @return Reference to the menu screen text.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getMenuScreenText(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = menuScreenTexts.find(key);
        if (it != menuScreenTexts.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a result text by key.
     *
     * @param key The lookup key.
     * @return Reference to the result text.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getResultText(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = resultTexts.find(key);
        if (it != resultTexts.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a unit name by key.
     *
     * @param key The lookup key.
     * @return Reference to the unit name.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getUnitName(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = unitNames.find(key);
        if (it != unitNames.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a unit description by key.
     *
     * @param key The lookup key.
     * @return Reference to the unit description.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getUnitDescription(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = unitDescriptions.find(key);
        if (it != unitDescriptions.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }

    /**
     * @brief Gets a voice actor name by key.
     *
     * @param key The lookup key.
     * @return Reference to the voice actor name.
     * @throws InvalidKeyException if the key does not exist.
     */
    const String& getVoiceActorName(const String& key) const {
        if (key.empty())
            return EMPTY_STRING;

        auto it = voiceActorNames.find(key);
        if (it != voiceActorNames.end())
            return it->second;
        else
            throw InvalidKeyException(fmt::format("{} is not a valid key", key));
    }
};
