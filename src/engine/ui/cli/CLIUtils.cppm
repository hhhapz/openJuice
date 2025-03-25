/**
 * @file CommandLineInterface.cppm
 * @brief Module file for command line interface operations.
 * 
 * This file contains the implementation of the command line interface operations.
 */

export module engine.ui.cli.CLIUtils;

#ifdef NO_RESERVED_STD
import std.core;
import std.io;
import std.text;
#else
import stdlib.core;
import stdlib.io;
import stdlib.text;
#endif


import engine.managers.GlobalSettings;
import engine.managers.TextManager;
import engine.utility.Exceptions;
import engine.utility.Language;
import engine.utility.EngineUtility;

using namespace exceptions;

/**
 * @namespace cliutils
 * @brief Namespace for command line interface operations.
 */
export namespace cliutils {
    /**
     * @brief Initialises the language for the command line interface.
     */
    void initialiseLanguage() {
        io::println("Enter your desired language:");
        io::println("Language codes: English [en], Japanese [jp], Simplified Chinese [chs], Traditional Chinese [cht], Russian [ru], Korean [ko], Spanish [sp], Portuguese (Brazil) [ptbr]");
        String languageInput;
        bool exitLoop = false;
        while (true) {
            io::getline(io::cin, languageInput);
            switch (engineutility::strings::hashString(languageInput.c_str())) {
                case engineutility::strings::hashString("en"):
                    GlobalSettings::getInstance().setLanguage(Language::English);
                    io::println("English selected");
                    exitLoop = true;
                    break;
                case engineutility::strings::hashString("jp"):
                    GlobalSettings::getInstance().setLanguage(Language::Japanese);
                    io::println("Japanese selected");
                    exitLoop = true;
                    break;
                case engineutility::strings::hashString("chs"):
                    GlobalSettings::getInstance().setLanguage(Language::SimplifiedChinese);
                    io::println("Simplified Chinese selected");
                    exitLoop = true;
                    break;
                case engineutility::strings::hashString("cht"):
                    GlobalSettings::getInstance().setLanguage(Language::TraditionalChinese);
                    io::println("Traditional Chinese selected");
                    exitLoop = true;
                    break;
                case engineutility::strings::hashString("ru"):
                    GlobalSettings::getInstance().setLanguage(Language::Russian);
                    io::println("Russian selected");
                    exitLoop = true;
                    break;
                case engineutility::strings::hashString("ko"):
                    GlobalSettings::getInstance().setLanguage(Language::Korean);
                    io::println("Korean selected");
                    exitLoop = true;
                    break;
                case engineutility::strings::hashString("sp"):
                    GlobalSettings::getInstance().setLanguage(Language::Spanish);
                    io::println("Spanish selected");
                    exitLoop = true;
                    break;
                case engineutility::strings::hashString("ptbr"):
                    GlobalSettings::getInstance().setLanguage(Language::PortugueseBR);
                    io::println("Portuguese (Brazil) selected");
                    exitLoop = true;
                    break;
                default:
                    io::println(io::stderr, "Invalid language code");
            }
            if (exitLoop)
                break;
        }
        TextManager::getInstance();
    }

    /**
     * @brief Initialises the frame rate for the command line interface.
     */
    void initialiseFrameRate() {
        io::println("Enter your desired frame rate (fps) (1-600):");
        io::println("Press Enter to use the default (60 fps).");

        String frameRateInput;
        
        while (true) {
            io::getline(io::cin, frameRateInput);
            if (frameRateInput.empty()) {
                GlobalSettings::getInstance().setFrameRate(60);
                io::println("Frame rate: 60 frames per second (default)");
                break;
            }

            try {
                usize pos;
                u64 frameRate = string::stoul(frameRateInput, &pos);

                if (pos == frameRateInput.size() && frameRate >= 1 && frameRate <= 600) {
                    GlobalSettings::getInstance().setFrameRate(static_cast<u16>(frameRate));
                    io::println("Frame rate: {} frames per second", string::to_string(frameRate));
                    break;
                }
            } catch (const Exception&) {
                io::println(io::stderr, "Invalid frame rate. Please enter a number between 1 and 600.");
            }
        }
    }
}