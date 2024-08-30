#include "game.hpp"

Game::Game() {

}

Game::~Game() {

}

void Game::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(gameDeck.begin(), gameDeck.end(), g);
}