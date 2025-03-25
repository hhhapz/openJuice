/**
 * @file Engine.cppm
 * @brief Engine implementation with threaded UI and game logic
 * 
 * This file contains the implementation of the game engine which manages
 * the main game loop and UI rendering in separate threads. It handles
 * thread synchronisation, state management, and the lifecycle of the game.
 */

export module engine.game.Engine;

#ifdef NO_RESERVED_STD
import std.core;
import std.concurrency;
import std.io;
import std.mem;
import std.sys;
import std.time;
#else
import stdlib.core;
import stdlib.concurrency;
import stdlib.io;
import stdlib.mem;
import stdlib.sys;
import stdlib.time;
#endif

import engine.game.Game;
import engine.managers.GlobalSettings;
import engine.managers.TextManager;
import engine.ui.CommandLineInterface;
import engine.ui.TextUserInterface;
import engine.ui.UserInterface;
import engine.utility.EngineUtility;

using namespace concurrency;
using mem::SharedPtr, mem::UniquePtr;

/**
 * @enum LaunchMode
 * @brief Launch modes for the game engine
 * 
 * Specifies which user interface should be used when running the game.
 */
export enum class LaunchMode {
    CLI, ///< Command Line Interface mode
    TUI  ///< Text User Interface mode
};

/**
 * @class Engine
 * @brief Main game engine class that manages game state and threading
 * 
 * The Engine class handles the core game loop, user interface, and thread
 * synchronisation. It uses separate threads for game logic and UI rendering
 * to ensure responsive gameplay even during computation-heavy operations.
 */
export class Engine {
private:
    LaunchMode launchMode; ///< The selected user interface mode
    SharedPtr<Game> game; ///< The main game instance containing game state
    
    Mutex stateMutex; ///< Mutex for thread-safe access to game state
    ConditionVariable gameUpdateCV; ///< Condition variable for signaling game thread
    AtomicBool running{true}; ///< Flag indicating if the engine is running
    AtomicBool gamePaused{false}; ///< Flag indicating if the game is paused
    
    Thread gameThread; ///< Thread for running game logic
    Thread uiThread; ///< Thread for running UI logic
    
    /**
     * @brief Runs the actual game loop (all computational parts of the game)
     * 
     * This method executes in its own thread and handles all game state updates.
     * It uses condition variables for pause/resume functionality and minimizes
     * lock duration to ensure UI responsiveness.
     */
    void runGameLoop() {
        while (running.load()) {
            {
                UniqueLock<Mutex> lock(stateMutex);
                gameUpdateCV.wait(lock, [this]() -> bool { 
                    return !gamePaused.load() || !running.load(); 
                });
                
                if (!running.load())
                    break;
            }
            
            {
                LockGuard<Mutex> lock(stateMutex);
                game->update(); 
            }
            
            this_thread::sleep_for(time::temporal::Milliseconds(16));
        }
    }
    
    /**
     * @brief Runs the UI loop (separate from game calculations)
     * 
     * This method executes in its own thread and handles all UI rendering and
     * event processing. It creates the appropriate UI based on the selected
     * launch mode and synchronises with the game thread for state access.
     */
    void runUILoop() {
        UniquePtr<UserInterface> ui;
        switch (launchMode) {
            case LaunchMode::CLI:
                ui = mem::make_unique<CommandLineInterface>(game, stateMutex);
                break;
            case LaunchMode::TUI:
                ui = mem::make_unique<TextUserInterface>(game, stateMutex);
                break;
            default:
                sys::unreachable();
        }
        
        ui->init();
        
        while (running.load()) {
            ui->processEvents();
            
            if (ui->shouldExit()) {
                running.store(false);
                gameUpdateCV.notify_all();
                break;
            }
            
            {
                LockGuard<Mutex> lock(stateMutex);
                ui->render();
            }
            
            this_thread::sleep_for(time::temporal::Milliseconds(33));
        }
    }

public:
    /**
     * @brief Constructs a new Engine object
     * 
     * @param mode The launch mode determining which UI to initialise
     */
    Engine(LaunchMode mode): 
        launchMode(mode), 
        game(mem::make_shared<Game>()) {}

    /**
     * @brief Destroy the Engine object
     */
    ~Engine() {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Shutting down engine");
        #endif

        if (running.load()) {
            stop();
            
            if (uiThread.joinable())
                uiThread.join();
            if (gameThread.joinable())
                gameThread.join();
        }

        #ifndef NDEBUG
        DebugLogger::getInstance().log("Engine shutdown complete!");
        #endif
    }
    
    /**
     * @brief Initialises and starts the engine
     * 
     * Launches both game and UI threads and waits for them to complete.
     * The UI thread drives the application lifecycle; when it exits,
     * this method ensures the game thread is also terminated properly.
     */
    void init() {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Initialising engine");
        #endif
        game->init();
        
        gameThread = Thread(&Engine::runGameLoop, this);
        uiThread = Thread(&Engine::runUILoop, this);
        
        uiThread.join();
        
        running.store(false);
        gameUpdateCV.notify_all();
        gameThread.join();
    }
    
    /**
     * @brief Pauses the game logic thread
     * 
     * Sets the paused flag to true, which causes the game thread to wait
     * on the condition variable until resumed.
     */
    void pause() {
        gamePaused.store(true);
    }
    
    /**
     * @brief Resumes the game logic thread if paused
     * 
     * Clears the paused flag and notifies the game thread to continue execution.
     */
    void resume() {
        gamePaused.store(false);
        gameUpdateCV.notify_all();
    }
    
    /**
     * @brief Signals all threads to stop and exit cleanly
     * 
     * Sets the running flag to false and notifies any waiting threads
     * to check their exit conditions.
     */
    void stop() {
        #ifndef NDEBUG
        DebugLogger::getInstance().log("Stopping engine");
        #endif
        running.store(false);
        gameUpdateCV.notify_all();
    }
    
    /**
     * @brief Get direct access to the game instance
     * 
     * @return SharedPtr<Game> Shared pointer to the game instance
     */
    SharedPtr<Game> getGame() const {
        return game;
    }
};
