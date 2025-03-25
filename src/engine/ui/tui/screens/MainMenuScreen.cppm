/**
 * @file MainMenuScreen.cppm
 * @brief Definition of the MainMenuScreen class.
 *
 * This file contains the definition of the MainMenuScreen class.
 */

export module engine.ui.tui.Screens:MainMenuScreen;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.mem;
import std.sys;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.mem;
import stdlib.sys;
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
 * @class MainMenuScreen
 * @brief Main menu screen implementation
 *
 * @extends TUIScreen
 */
export class MainMenuScreen final: public TUIScreen {
private:
    bool initialised = false; ///< Whether the screen has been initialised
    i32 selectedOption = 0; ///< The current option selected
    Vector<String> menuOptions = {
        TextManager::getInstance().getMenuScreenText("PLAYMENU_FREEBATTLE"), // Multiplayer
        TextManager::getInstance().getMenuScreenText("PLAYMENU_CAMPAIGN"), // Campaign
        TextManager::getInstance().getMenuScreenText("PLAYMENU_SHOP"), // Shop
        TextManager::getInstance().getMenuScreenText("PLAYMENU_PROFILE"), // Profile
        TextManager::getInstance().getMenuScreenText("PLAYMENU_CODEX"), // OJDex
        TextManager::getInstance().getMenuScreenText("PLAYMENU_MANUAL"), // Guide
        TextManager::getInstance().getMenuScreenText("PLAYMENU_WIKI"), // Wiki
        TextManager::getInstance().getMenuScreenText("MENU_BUTTON_GAME_CONFIG"), // Config
        "Credits", // Credits
        TextManager::getInstance().getMenuScreenText("PLAYMENU_EXIT") // Exit to title
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
                    case 0: // Multiplayer
                        screenSwitchCallback(ScreenType::MultiplayerLobbySelect);
                        return true;
                    case 1: // Singleplayer
                        screenSwitchCallback(ScreenType::SingleplayerLobbySelect);
                        return true;
                    case 2: // Shop
                        screenSwitchCallback(ScreenType::Shop);
                        return true;
                    case 3: // Profile
                        screenSwitchCallback(ScreenType::Profile);
                        return true;
                    case 4: // OJDex
                        screenSwitchCallback(ScreenType::OJDex);
                        return true;
                    case 5: // Guide
                        screenSwitchCallback(ScreenType::Guide);
                        return true;
                    case 6: // Wiki
                        screenSwitchCallback(ScreenType::Wiki);
                        return true;
                    case 7: // Config
                        screenSwitchCallback(ScreenType::Config);
                        return true;
                    case 8: // Credits
                        screenSwitchCallback(ScreenType::Credits);
                        return true;
                    case 9: // Exit to title
                        screenSwitchCallback(ScreenType::Title);
                        return true;
                    default:
                        sys::unreachable();
                }
            }
            return false;
        });

        component = Renderer(componentWithEvents, [this]() -> Element {
            return vbox({
                text("openJuice") | bold | center,
                separator(),
                hbox({
                    text(" "),
                    menu->Render() | flex,
                    text(" ")
                }),
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
     * @brief Constructor for the MainMenuScreen class
     *
     * @param game Shared pointer to the game
     * @param callback Function to call when switching screens
     */
    MainMenuScreen(SharedPtr<Game> game, Function<void(ScreenType)> callback):
        TUIScreen(game, callback) {
        createComponent();
    }

    /**
     * @brief Called when screen becomes active
     */
    void onActivate() override {
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
};
