module;

#include <string>

export module engine.utility.GlobalSettings;

export import :Language;

export class GlobalSettings {
private:
    Language language;

    GlobalSettings():
        language{Language::English} {}
public:
    static GlobalSettings& getInstance() {
        static GlobalSettings instance;
        return instance;
    }

    void setLanguage(Language lang) {
        language = lang;
    }

    Language getLanguage() const {
        return language;
    }
};