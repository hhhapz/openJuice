/**
 * @file TitleScreen.cppm
 * @brief Definition of the TitleScreen class.
 *
 * This file contains the definition of the TitleScreen class.
 */

export module engine.ui.tui.Screens:TitleScreen;

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
import engine.managers.ProfileManager;
import engine.managers.TextManager;
import engine.ui.tui.ScreenType;
import engine.ui.tui.TUIScreen;

import ftxui.component;
import ftxui.dom;

using namespace collections;
using mem::SharedPtr;

using namespace ftxui;

/**
 * @class TitleScreen
 * @brief Title screen implementation
 *
 * @extends TUIScreen
 */
export class TitleScreen final: public TUIScreen {
private:
    bool exitSelected = false; ///< Whether the entire application should exit
    bool initialised = false; ///< Whether the screen has been initialised
    i32 selectedOption = 0; ///< The current option selected
    Vector<String> menuOptions = {
        TextManager::getInstance().getMenuScreenText("MAINMENU_NEWGAME"), // New game
        TextManager::getInstance().getMenuScreenText("MAINMENU_LOADGAME"), // Continue
        TextManager::getInstance().getMenuScreenText("MAINMENU_CONFIGURATION"), // Config
        TextManager::getInstance().getMenuScreenText("MAINMENU_EXIT") // Exit game
    };

    Component menu;

    /**
     * @brief Creates the screen component
     */
    void createComponent() override {
        if (initialised)
            return;

        menu = Menu(&menuOptions, &selectedOption);

        Component componentWithEvents = CatchEvent(menu, [this](Event event) -> bool {
            if ((event.is_mouse() && event.mouse().button == Mouse::Left) || (event == Event::Return)) {
                switch (selectedOption) {
                    case 0: // New Game
                        ProfileManager::getInstance().resetProfile();
                        screenSwitchCallback(ScreenType::MainMenu);
                        return true;
                    case 1: // Continue
                        ProfileManager::getInstance().loadProfile();
                        screenSwitchCallback(ScreenType::MainMenu);
                        return true;
                    case 2: // Configuration
                        screenSwitchCallback(ScreenType::Config);
                        return true;
                    case 3: // Exit
                        exitSelected = true;
                        screenSwitchCallback(ScreenType::Exit);
                        return true;
                }
            }
            return false;
        });

        component = Renderer(componentWithEvents, [this]() -> Element {
            return vbox({
                text("openJuice") | bold | center,
                separator(),
                menu->Render() | center,
                separator(),
                text("Version 0.0.1") | center,
            }) | border | flex;
        });

        initialised = true;
    }

    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    void noop() const override {}
public:
    /**
     * @brief Constructor for the TitleScreen class
     *
     * @param game Shared pointer to the game
     * @param callback Function to call when switching screens
     */
    TitleScreen(SharedPtr<Game> game, Function<void(ScreenType)> callback):
        TUIScreen(game, callback) {
        createComponent();
    }

    /**
     * @brief Called when screen becomes active
     */
    void onActivate() override {
        exitSelected = false;
        selectedOption = 0;
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

    /**
     * @brief Check if the user requested to exit
     *
     * @return True if exit was selected
     */
     bool shouldExit() const override {
        return exitSelected;
    }
};
