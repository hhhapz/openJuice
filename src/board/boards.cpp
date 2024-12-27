#include "../../include/board/boards.hpp"

BoardLibrary& BoardLibrary::getInstance() {
    static BoardLibrary instance;
    return instance;
}

void loadBoards(const std::string& directory) {
    for (const auto& entry: std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == ".toml") {
            std::string boardPath = entry.path().string();
            toml::table data = toml::parse_file(boardPath);
        }
    }
}