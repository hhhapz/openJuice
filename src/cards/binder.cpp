#include "binder.hpp"

CardLibrary::CardLibrary() {}

CardLibrary::~CardLibrary() {}

std::string CardLibrary::getCardDescription(int id) const {
    std::ifstream descriptionFile{"descriptions.txt"};
    std::string description;
    int currentLine = 0;
    if (!descriptionFile.is_open())
        throw FileException("Error opening descriptions file!");
    while (std::getline(descriptionFile, description)) {
        if (++currentLine == id)
            return description;
    }
    throw FileException("Invalid ID value:" + std::to_string(id));
}