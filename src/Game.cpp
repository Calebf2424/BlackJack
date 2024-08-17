#include "Game.h"
#include "Cards.h"
#include <cctype>

Game::Game() : deck(nullptr), _playerScore(0), _dealerScore(0){}
Game::~Game() {if (deck) delete deck;}
void Game::start() {
    deck = new CardDeck();
    while (_playAgain) {
        runGame();
    }
}

void Game::runGame() {

}

void Game::playAgain() {
    char c = handleInputYN();
    _playAgain = (c == 'Y');
}

void Game::quit() {
    delete this;
}

char Game::handleInputYN() {
    char input;
    bool valid = false;
    while (!valid) {
        std::cout << "Enter Y/N" << std::endl;
        std::cin >> input;
        input = std::toupper(input);
        if (input == 'Y' || 'N') {
            valid = true;
        } else {
            std::cout << "Invalid input" << std::endl;
        }
    }
    return input;
}

void Game::updateBoard() {

}
