/**
 * @file MultiplayerGameLobbyScreen.cppm
 * @brief Definition of the MultiplayerGameLobbyScreen class.
 *
 * This file contains the definition of the MultiplayerGameLobbyScreen class.
 */

export module engine.ui.tui.Screens:MultiplayerGameLobbyScreen;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.mem;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.mem;
#endif

import engine.game.Game;
import engine.managers.TextManager;
import engine.ui.tui.ScreenType;
import engine.ui.tui.TUIScreen;

import ftxui.component;
import ftxui.dom;

using namespace collections;
using mem::SharedPtr;

using namespace ftxui;

/**
 * @class MultiplayerGameLobbyScreen
 * @brief Multiplayer game lobby screen implementation
 *
 * @extends TUIScreen
 */
export class MultiplayerGameLobbyScreen final: public TUIScreen {
    private:
    bool initialised = false;

    /**
     * @brief Creates the screen component
     */
    void createComponent() override {

    }

    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    void noop() const override {}
public:
    /**
     * @brief Constructor for the MultiplayerGameLobbyScreen class
     *
     * @param game Shared pointer to the game
     * @param callback Function to call when switching screens
     */
    MultiplayerGameLobbyScreen(SharedPtr<Game> game, Function<void(ScreenType)> callback):
        TUIScreen(game, callback) {
        createComponent();
    }

    /**
     * @brief Called when screen becomes active
     */
    void onActivate() override {
    
    }

    /**
     * @brief Called when screen becomes inactive
     */
    void onDeactivate() override {

    }

    /**
     * @brief Update screen
     */
    void update() override {

    }
};
