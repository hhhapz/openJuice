module;

#include <iostream>
#include <print>

export module engine.game.Game;

import entity.Bosses;
import entity.Characters;
import entity.Enemies;

import card.Cards;
import engine.board.Board;
import engine.utility.Colours;
import engine.utility.GlobalSettings;
import engine.utility.Language;
import engine.utility.Utility;

export class Game {
private:
public:
    Game(); 
    void run();
};

void Game::run() {
    GlobalSettings::getInstance();

    std::println("Enter your desired language:");
    std::println("Language codes: English [en], Japanese [ja], Simplified Chinese [zh-s], Traditional Chinese [zh-t], Russian [ru], German [de], French [fr], Spanish [es]");
    std::string languageInput;
    bool exitLoop = false;
    while (true) {
        std::getline(std::cin, languageInput);
        if (languageInput == "en") {
            GlobalSettings::getInstance().setLanguage(Language::English);
            break;
        } else if (languageInput == "ja") {
            GlobalSettings::getInstance().setLanguage(Language::Japanese);
            break;
        } else if (languageInput == "zh-s") {
            GlobalSettings::getInstance().setLanguage(Language::SimplifiedChinese);
            break;
        } else if (languageInput == "zh-t") {
            GlobalSettings::getInstance().setLanguage(Language::TraditionalChinese);
            break;
        } else if (languageInput == "ru") {
            GlobalSettings::getInstance().setLanguage(Language::Russian);
            break;
        } else if (languageInput == "de") {
            GlobalSettings::getInstance().setLanguage(Language::German);
            break;
        } else if (languageInput == "fr") {
            GlobalSettings::getInstance().setLanguage(Language::French);
            break;
        } else if (languageInput == "es") {
            GlobalSettings::getInstance().setLanguage(Language::Spanish);
            break;
        } else {
            std::println("Invalid language code. Please enter a valid language code.");
        }
    }
}