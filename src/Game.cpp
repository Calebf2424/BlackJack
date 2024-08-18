#include "Game.h"
#include "Cards.h"
#include <cctype>

Game::Game() : cardDeck(nullptr), _playerScore(0), _dealerScore(0){}
Game::~Game() {if (cardDeck) delete cardDeck;}
void Game::start() {
    cardDeck = new CardDeck();
    cardDeck->createDeck();
    while (_playAgain) {
        runGame();
    }
}

void Game::runGame() {
    std::cout << "Black Jack" << std::endl;
    cardDeck->shuffleDeck();

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
        if (input == 'Y' || input == 'N') {
            valid = true;
        } else {
            std::cout << "Invalid input" << std::endl;
        }
    }
    return input;
}

void Game::clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}


