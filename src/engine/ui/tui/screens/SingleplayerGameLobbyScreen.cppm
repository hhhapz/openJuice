/**
 * @file SingleplayerGameLobbyScreen.cppm
 * @brief Definition of the SingleplayerGameLobbyScreen class.
 *
 * This file contains the definition of the SingleplayerGameLobbyScreen class.
 */

export module engine.ui.tui.Screens:SingleplayerGameLobbyScreen;

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

using namespace stdlib::collections;
using stdlib::mem::SharedPtr;

using namespace ftxui;

/**
 * @class SingleplayerGameLobbyScreen
 * @brief Singleplayer game lobby screen implementation
 *
 * @extends TUIScreen
 */
export class SingleplayerGameLobbyScreen final: public TUIScreen {
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
     * @brief Constructor for the SingleplayerGameLobbyScreen class
     *
     * @param game Shared pointer to the game
     * @param callback Function to call when switching screens
     */
    SingleplayerGameLobbyScreen(SharedPtr<Game> game, Function<void(ScreenType)> callback):
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
