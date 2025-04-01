/**
 * @file ScreenType.cppm
 * @brief Enum of screen types used by the TUI
 */

module;

#include <format>

export module engine.ui.tui.ScreenType;

#ifdef NO_RESERVED_STD
import std.core;
import std.fmt;
import std.sys;
#else
import stdlib.core;
import stdlib.fmt;
import stdlib.sys;
#endif

using stdlib::fmt::FormatContext;
using stdlib::fmt::FormatParseContext;

/**
 * @enum ScreenType
 * @brief All possible screen types that the game screen can be in
 */
export enum class ScreenType {
    Exit, ///< Exit (not a screen)
    Loading, ///< Loading screen
    Title, ///< Title screen
    MainMenu, ///< Game main menu screen
    SingleplayerLobbySelect, ///< Game lobby selection screen (singleplayer)
    SingleplayerCustom, ///< Singleplayer custom mode screen
    SingleplayerCampaignSelect, ///< Singleplayer campaign selection screen
    MultiplayerLobbySelect, ///< Game lobby selection screen (multiplayer)
    MultiplayerCustom, ///< Multiplayer customisation screen
    SingleplayerGameLobby, ///< Game lobby screen (singleplayer)
    MultiplayerGameLobby, ///< Game lobby screen (multiplayer)
    CharacterSelect, ///< Character selection screen
    CardSelect, ///< Card selection screen
    Gameplay, ///< Actual game
    GameResults, ///< Game results screen
    Shop, ///< Shop screen
    Profile, ///< Profile screen
    OJDex, ///< OJDex menu screen
    Guide, ///< Guide/tutorial menu screen
    Wiki, ///< Wiki (not a screen)
    Config, ///< Config/settings menu screen
    Credits, ///< Credits menu screen
    Pause ///< Game paused screen
};

// Must use std::formatter, not fmt::Formatter
template<>
struct std::formatter<ScreenType> {
    constexpr auto parse(FormatParseContext& ctx) -> const char* {
        return ctx.begin();
    }

    auto format(const ScreenType& st, FormatContext& ctx) const {
        StringView name;
        switch (st) {
            case ScreenType::Exit:
                name = "Exit";
                break;
            case ScreenType::Loading:
                name = "Loading";
                break;
            case ScreenType::Title:
                name = "Title";
                break;
            case ScreenType::MainMenu:
                name = "Main Menu";
                break;
            case ScreenType::SingleplayerLobbySelect:
                name = "Singleplayer Lobby Selection";
                break;
            case ScreenType::SingleplayerCustom:
                name = "Singleplayer Custom";
                break;
            case ScreenType::SingleplayerCampaignSelect:
                name = "Singleplayer Campaign Selection";
                break;
            case ScreenType::MultiplayerLobbySelect:
                name = "Multiplayer Lobby Selection";
                break;
            case ScreenType::MultiplayerCustom:
                name = "Multiplayer Custom";
                break;
            case ScreenType::SingleplayerGameLobby:
                name = "Singleplayer Game Lobby";
                break;
            case ScreenType::MultiplayerGameLobby:
                name = "Multiplayer Game Lobby";
                break;
            case ScreenType::CharacterSelect:
                name = "Character Selection";
                break;
            case ScreenType::CardSelect:
                name = "Card Selection";
                break;
            case ScreenType::Gameplay:
                name = "Gameplay";
                break;
            case ScreenType::GameResults:
                name = "Game Results";
                break;
            case ScreenType::Shop:
                name = "Shop";
                break;
            case ScreenType::Profile:
                name = "Profile";
                break;
            case ScreenType::OJDex:
                name = "OJDex";
                break;
            case ScreenType::Guide:
                name = "Guide";
                break;
            case ScreenType::Wiki:
                name = "Wiki";
                break;
            case ScreenType::Config:
                name = "Configuration";
                break;
            case ScreenType::Credits:
                name = "Credits";
                break;
            case ScreenType::Pause:
                name = "Pause";
                break;
            default:
                sys::unreachable();
        }
        return fmt::format_to(ctx.out(), "{}", name);
    }
};

export template struct std::formatter<ScreenType>;