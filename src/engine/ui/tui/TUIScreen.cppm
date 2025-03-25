/**
 * @file TUIScreen.cppm
 * @brief Base class for all TUI screens
 */

export module engine.ui.tui.TUIScreen;

#ifdef NO_RESERVED_STD
import std.core;
import std.mem;
#else
import stdlib.core;
import stdlib.mem;
#endif

import engine.game.Game;
import engine.ui.tui.ScreenType;
import engine.utility.Interfaces;

import ftxui.component;

using mem::SharedPtr;

using namespace ftxui;

/**
 * @class TUIScreen
 * @brief Abstract base class for all TUI screens
 * 
 * @implements FinalOnly
 */
export class TUIScreen: public FinalOnly {
protected:
    SharedPtr<Game> game;
    Component component;
    Function<void(ScreenType)> screenSwitchCallback;

    /**
     * @brief Creates the screen component
     */
    virtual void createComponent() = 0;

    /**
     * @brief Constructor for the TUIScreen class
     * 
     * @param game Shared pointer to the game
     * @param callback Function to call when switching screens
     */
    TUIScreen(SharedPtr<Game> game, Function<void(ScreenType)> callback):
        game{game}, screenSwitchCallback{callback} {}
    
    virtual ~TUIScreen() = default;
public:
    /**
     * @brief Get the FTXUI component for this screen
     * 
     * @return The component
     */
    virtual Component getComponent() const {
        return component;
    }

    /**
     * @brief Called when the screen becomes active
     */
    virtual void onActivate() = 0;

    /**
     * @brief Called when the screen becomes inactive
     */
    virtual void onDeactivate() = 0;

    /**
     * @brief Update screen logic
     */
    virtual void update() = 0;

    /**
     * @brief Check if the screen requested exit
     * 
     * @return True if exit was requested, else false
     */
    virtual bool shouldExit() const {
        return false;
    }
};