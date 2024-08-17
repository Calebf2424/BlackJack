#include "Game.h"
#include "Cards.h"

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
    char c = handleInput();
    _playAgain = (c == 'Y');
}

void Game::quit() {
    delete this;
}

char Game::handleInput() {
    
}

void Game::updateBoard() {

}
