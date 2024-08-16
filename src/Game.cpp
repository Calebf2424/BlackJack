#include "Game.h"
#include "Cards.h"

Game::Game() : deck(nullptr), _playerScore(0), _dealerScore(0){}
Game::~Game() {if (deck) delete deck;}
void Game::start() {
    deck = new CardDeck();
}

void Game::runGame() {

}

void Game::playAgain() {

}

void Game::quit() {
    
}

void Game::handleInput() {

}

void Game::updateBoard() {

}
