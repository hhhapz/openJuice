/**
 * @file ScreenType.cppm
 * @brief Enum of screen types used by the TUI
 */

export module engine.ui.tui.ScreenType;

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
