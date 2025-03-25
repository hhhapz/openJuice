/**
 * @file GameInfo.cppm
 * @brief Definition of game-related constants.
 *
 * This file contains the definition of constants related to the game, such as maximum dimensions and player count.
 */

export module engine.utility.GameInfo;

#ifdef NO_RESERVED_STD
import std.core;
#else
import stdlib.core;
#endif

/**
 * @namespace RuntimePaths
 * @brief Namespace for runtime game file access locations.
 */
export namespace RuntimePaths {
    constexpr inline char USERDATA_DIR[] = "./userdata"; ///< The user data directory path.
    constexpr inline char MAPS_DIR[] = "./maps"; ///< The maps directory path.
    constexpr inline char PATH_DEBUGFILE[] = "./userdata/debug.txt"; ///< The debug file path.
    constexpr inline char PATH_SAVEFILE[] = "./userdata/savedata.toml"; ///< The save file path.
}

/**
 * @namespace AssetPaths
 * @brief Namespace for game-related file locations.
 */
export namespace AssetPaths {
    constexpr inline char PATH_ABILITIES_FILE[] = "./assets/define/{}/abilities.txt"; ///< File containing ability localisation
    constexpr inline char PATH_CARDARTISTS_FILE[] = "./assets/define/{}/cardartists.txt"; ///< File containing card artist localisation
    constexpr inline char PATH_CARDS_FILE[] = "./assets/define/{}/cards.txt"; ///< File containing main cards localisation
    constexpr inline char PATH_CARDS_2_FILE[] = "./assets/define/{}/cards_2.txt"; ///< File containing secondary cards localisation
    constexpr inline char PATH_CARDS_BOUNTY_FILE[] = "./assets/define/{}/cards_bounty.txt"; ///< File containing bounty mode card localisation
    constexpr inline char PATH_CARDS_COOP_FILE[] = "./assets/define/{}/cards_coop.txt"; ///< File containing co-op mode card localisation
    constexpr inline char PATH_CARDS_EFFECT_COOP_FILE[] = "./assets/define/{}/cards_effect_coop.txt"; ///< File containing co-op mode card effect localisation
    constexpr inline char PATH_CARDS_EFFECT_FILE[] = "./assets/define/{}/cards_effect.txt"; ///< File containing general card effect localisation
    constexpr inline char PATH_CARDS_MISC_FILE[] = "./assets/define/{}/cards_misc.txt"; ///< File containing miscellaneous cards localisation
    constexpr inline char PATH_CARDS_MUSHROOM_FILE[] = "./assets/define/{}/cards_mushroom.txt"; ///< File containing mushroom cards localisation
    constexpr inline char PATH_CHALLENGES_FILE[] = "./assets/define/{}/challenges.txt"; ///< File containing challenge localisation
    constexpr inline char PATH_CHAOS_MUTATORS_FILE[] = "./assets/define/{}/chaos_mutators.txt"; ///< File containing chaos mutator localisation
    constexpr inline char PATH_CHARACTERSELECT_FILE[] = "./assets/define/{}/characterselect.txt"; ///< File containing character selection localisation
    constexpr inline char PATH_CODEX_FILE[] = "./assets/define/{}/codex.txt"; ///< File containing codex/lore localisation
    constexpr inline char PATH_COMMENT_FILE[] = "./assets/define/{}/comment.txt"; ///< File containing UI comments and messages
    constexpr inline char PATH_CONFIG_FILE[] = "./assets/define/{}/config.txt"; ///< File containing configuration settings localisation
    constexpr inline char PATH_CONSUMABLES_FILE[] = "./assets/define/{}/consumables.txt"; ///< File containing consumable item localisation
    constexpr inline char PATH_ERROR_FILE[] = "./assets/define/{}/error.txt"; ///< File containing error messages
    constexpr inline char PATH_EVENTNAMES_FILE[] = "./assets/define/{}/eventnames.txt"; ///< File containing event name localisation
    constexpr inline char PATH_FIELDEVENTS_FILE[] = "./assets/define/{}/fieldevents.txt"; ///< File containing field event localisation
    constexpr inline char PATH_FIELDNAMES_FILE[] = "./assets/define/{}/fieldnames.txt"; ///< File containing field name localisation
    constexpr inline char PATH_GAME_MESSAGE_FILE[] = "./assets/define/{}/game_message.txt"; ///< File containing game message localisation
    constexpr inline char PATH_GAME_NORMA_FILE[] = "./assets/define/{}/game_norma.txt"; ///< File containing norma level localisation
    constexpr inline char PATH_GAME_SYSTEM_FILE[] = "./assets/define/{}/game_system.txt"; ///< File containing game system messages
    constexpr inline char PATH_GAME_TUTORIAL_FILE[] = "./assets/define/{}/game_tutorial.txt"; ///< File containing tutorial messages
    constexpr inline char PATH_LAUNCHER_FILE[] = "./assets/define/{}/launcher.txt"; ///< File containing launcher localisation
    constexpr inline char PATH_MENUSCREENS_FILE[] = "./assets/define/{}/menuscreens.txt"; ///< File containing menu screen localisation
    constexpr inline char PATH_MIXERS_FILE[] = "./assets/define/{}/mixers.txt"; ///< File containing mixer localisation
    constexpr inline char PATH_MULTIPLAYER_FILE[] = "./assets/define/{}/multiplayer.txt"; ///< File containing multiplayer localisation
    constexpr inline char PATH_PETS_FILE[] = "./assets/define/{}/pets.txt"; ///< File containing pet localisation
    constexpr inline char PATH_PINS_FILE[] = "./assets/define/{}/pins.txt"; ///< File containing pin localisation
    constexpr inline char PATH_PROFILE_FILE[] = "./assets/define/{}/profile.txt"; ///< File containing profile localisation
    constexpr inline char PATH_RESULT_FILE[] = "./assets/define/{}/result.txt"; ///< File containing result screen localisation
    constexpr inline char PATH_SHOP_FILE[] = "./assets/define/{}/shop.txt"; ///< File containing shop localisation
    constexpr inline char PATH_UNIT_GAMES_FILE[] = "./assets/define/{}/unitgames.txt"; ///< File containing unit game localisation
    constexpr inline char PATH_UNITS_FILE[] = "./assets/define/{}/units.txt"; ///< File containing unit localisation
    constexpr inline char PATH_VOICEACTORS_FILE[] = "./assets/define/{}/voiceactors.txt"; ///< File containing voice actor localisation
}

/**
 * @namespace GameInfo
 * @brief Namespace for game-related constants.
 */
export namespace GameInfo {
    constexpr inline usize GAME_MAX_WIDTH = 20; ///< Maximum game width.
    constexpr inline usize GAME_MAX_HEIGHT = 20; ///< Maximum game height.
    constexpr inline u8 MAX_PLAYERS = 4; ///< Maximum number of players.
    constexpr inline usize MAX_DICEROLL_HISTORY_SIZE = 100; ///< Maximum number of dice rolls stored.
}