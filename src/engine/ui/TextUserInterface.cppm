/**
 * @file TextUserInterface.cppm
 * @brief Text user interface implementation
 */

export module engine.ui.TextUserInterface;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.concurrency;
import std.io;
import std.mem;
import std.sys;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.concurrency;
import stdlib.io;
import stdlib.mem;
import stdlib.sys;
#endif

import engine.game.Game;
import engine.managers.GlobalSettings;
import engine.ui.tui.Screens;
import engine.ui.tui.ScreenType;
import engine.ui.tui.TUIScreen;
import engine.ui.tui.TUIUtils;
import engine.ui.UserInterface;
import engine.utility.EngineUtility;

import ftxui.component;

using namespace collections;
using namespace concurrency;
using mem::SharedPtr;

using namespace ftxui;

/**
 * @class TextUserInterface
 * @brief
 *
 * @extends UserInterface
 */
export class TextUserInterface: public UserInterface {
private:
    ScreenInteractive screen = ScreenInteractive::Fullscreen(); ///< Main screen
    ScreenType currentScreen = ScreenType::Title; ///< The current active screen type
    Component activeComponent; ///< Active FTXUI component

    Map<ScreenType, SharedPtr<TUIScreen>> screens; ///< Map storing all initialised screens

    /**
     * @brief Get or create screen if it doesn't exist
     *
     * @param type Screen type to get
     * @return SharedPtr<TUIScreen> to the requested screen
     */
    SharedPtr<TUIScreen> getScreen(ScreenType type) {
        auto switchCallback = [this](ScreenType newType) -> void {
            switchScreen(newType);
        };

        if (!screens.contains(type)) {
            switch (type) {
                case ScreenType::Loading:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Loading screen");
                    #endif

                    screens[type] = mem::make_shared<LoadingScreen>(game, switchCallback);
                    break;
                case ScreenType::Title:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Title screen");
                    #endif

                    screens[type] = mem::make_shared<TitleScreen>(game, switchCallback);
                    break;
                case ScreenType::MainMenu:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Main Menu screen");
                    #endif

                    screens[type] = mem::make_shared<MainMenuScreen>(game, switchCallback);
                    break;
                case ScreenType::SingleplayerLobbySelect:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Singleplayer Lobby Select screen");
                    #endif

                    screens[type] = mem::make_shared<SingleplayerLobbySelectScreen>(game, switchCallback);
                    break;
                case ScreenType::SingleplayerCustom:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Singleplayer Custom screen");
                    #endif

                    screens[type] = mem::make_shared<SingleplayerCustomScreen>(game, switchCallback);
                    break;
                case ScreenType::SingleplayerCampaignSelect:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Singleplayer Campaign Select screen");
                    #endif

                    screens[type] = mem::make_shared<SingleplayerCampaignSelectScreen>(game, switchCallback);
                    break;
                case ScreenType::MultiplayerLobbySelect:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Multiplayer Lobby Select screen");
                    #endif

                    screens[type] = mem::make_shared<MultiplayerLobbySelectScreen>(game, switchCallback);
                    break;
                case ScreenType::MultiplayerCustom:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Multiplayer Custom screen");
                    #endif

                    screens[type] = mem::make_shared<MultiplayerCustomScreen>(game, switchCallback);
                    break;
                case ScreenType::SingleplayerGameLobby:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Singleplayer Game Lobby screen");
                    #endif
                    
                    screens[type] = mem::make_shared<SingleplayerGameLobbyScreen>(game, switchCallback);
                    break;
                case ScreenType::MultiplayerGameLobby:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Multiplayer Game Lobby screen");
                    #endif

                    screens[type] = mem::make_shared<MultiplayerGameLobbyScreen>(game, switchCallback);
                    break;
                case ScreenType::CharacterSelect:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Character Select screen");
                    #endif

                    screens[type] = mem::make_shared<CharacterSelectScreen>(game, switchCallback);
                    break;
                case ScreenType::CardSelect:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Card Select screen");
                    #endif

                    screens[type] = mem::make_shared<CardSelectScreen>(game, switchCallback);
                    break;
                case ScreenType::Gameplay:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Gameplay screen");
                    #endif

                    screens[type] = mem::make_shared<GameplayScreen>(game, switchCallback);
                    break;
                case ScreenType::GameResults:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Game Results screen");
                    #endif

                    screens[type] = mem::make_shared<GameResultsScreen>(game, switchCallback);
                    break;
                case ScreenType::Shop:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Shop screen");
                    #endif

                    screens[type] = mem::make_shared<ShopScreen>(game, switchCallback);
                    break;
                case ScreenType::Profile:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Profile screen");
                    #endif

                    screens[type] = mem::make_shared<ProfileScreen>(game, switchCallback);
                    break;
                case ScreenType::OJDex:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating OJDex screen");
                    #endif 

                    screens[type] = mem::make_shared<OJDexScreen>(game, switchCallback);
                    break;
                case ScreenType::Guide:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Guide screen");
                    #endif

                    screens[type] = mem::make_shared<GuideScreen>(game, switchCallback);
                    break;
                case ScreenType::Config:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Config screen");
                    #endif

                    screens[type] = mem::make_shared<ConfigScreen>(game, switchCallback);
                    break;
                case ScreenType::Credits:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Credits screen");
                    #endif

                    screens[type] = mem::make_shared<CreditsScreen>(game, switchCallback);
                    break;
                case ScreenType::Pause:
                    #ifndef NDEBUG
                    DebugLogger::getInstance().log("Creating Pause screen");
                    #endif

                    screens[type] = mem::make_shared<PauseScreen>(game, switchCallback);
                    break;
                default:
                    sys::unreachable();
            }
        }

        return screens[type];
    }

    /**
     * @brief Switch to a different screen
     *
     * @param type The screen to switch to
     */
    void switchScreen(ScreenType type) {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("TextUserInterface: switching to screen type {}", type);
        #endif

        if (type == ScreenType::Exit) {
            #ifndef NDEBUG
            DebugLogger::getInstance().log("Exiting TUI");
            #endif

            requestExit();
            screen.ExitLoopClosure()();
            return;
        }

        try {
            if (screens.contains(currentScreen) && currentScreen != type) {
                #ifndef NDEBUG
                DebugLogger::getInstance().log("TextUserInterface: deactivating current screen {}", currentScreen);
                #endif
                
                screens[currentScreen]->onDeactivate();
            }

            currentScreen = type;

            #ifndef NDEBUG
            DebugLogger::getInstance().log("TextUserInterface: getting new screen {}", currentScreen);
            #endif

            SharedPtr<TUIScreen> handlingScreen = getScreen(type);
            handlingScreen->onActivate();

            #ifndef NDEBUG
            DebugLogger::getInstance().log("TextUserInterface: screen switch complete");
            #endif

            activeComponent = handlingScreen->getComponent();

            screen.ExitLoopClosure()();

        } catch (const Exception& e) {
            DebugLogger::getInstance().log("An error occured in switching screens");
        }
    }

    /**
     * @brief
     *
     * @return true if there is input, false otherwise
     */
    bool hasInput() {
        return false;
    }

    /**
     * @brief
     *
     * @return String
     */
    String readInput() {
        return "";
    }

    /**
     * @brief
     *
     * @param cmd
     */
    void processCommand(const String& cmd) {
        return;
    }
public:
    /**
     * @brief Constructor that initialises the base UserInterface
     * @param state Shared pointer to game instance
     * @param mutex Reference to state mutex for synchronisation
     */
    TextUserInterface(SharedPtr<Game> game, Mutex& mutex):
        UserInterface(game, mutex) {}

    /**
     * @brief
     */
    void init() override {
        switchScreen(ScreenType::Title);
    }

    /**
     * @brief
     */
    void processEvents() override {
        if (hasInput()) {
            String command = readInput();

            if (command == "exit") {
                requestExit();
            } else {
                LockGuard<Mutex> lock(stateMutex);
                processCommand(command);
            }
        }
    }

    /**
     * @brief
     */
    void render() override {
        if (!exitRequested.load() && activeComponent)
            screen.Loop(activeComponent);
    }
};
