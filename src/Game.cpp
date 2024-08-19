#include "Game.h"
#include "Cards.h"
#include <cctype>

Game::Game();
Game::~Game() {if (cardDeck) delete cardDeck;}

void Game::runGame() {
    std::cout << "Black Jack" << std::endl;
    cardDeck->shuffleDeck();
    cardDeck->addToDealerDeck();
    cardDeck->addToPlayerDeck();
    cardDeck->addToPlayerDeck();
    cardDeck->updateBoard();

    // Check for initial Blackjacks
    if (cardDeck->playerBlackJack()) {
        setWin();
        calculateWinner();
        return;
    }
    if (cardDeck->dealerBlackJack()) {
        calculateWinner();
        return;
    }

    // Player's turn
    int pScore = cardDeck->getPlayerScore();
    while (pScore < 21) {
        std::cout << "Hit? ";
        char choice = handleInputYN();
        if (choice == 'Y') {
            cardDeck->addToPlayerDeck();
            cardDeck->updateBoard();
            pScore = cardDeck->getPlayerScore();
            cardDeck->hasPlayerBust();
            if (_playerBust) {
                calculateWinner();
                return;
            }
        } else {
            break;
        }
    }

    // Dealer's turn
    int dScore = cardDeck->getDealerScore();
    while (dScore < 17) {
        cardDeck->addToDealerDeck();
        cardDeck->updateBoard();
        dScore = cardDeck->getDealerScore();
        cardDeck->hasDealerBust();
        if (_dealerBust) {
            setWin();
            calculateWinner();
            return;
        }
    }

    // Determine the outcome
    if(pScore > dScore) {
        setWin();
    } else if (pScore == dScore) {
        setDraw();
    }
    calculateWinner();
}

void Game::calculateWinner() {
    if (getDraw()) {
        std::cout << "Game is a Draw !!" << std::endl;
        return;
    }
    bool win = getWin();
    win ? std::cout << "Player Wins!!" << std::endl : std::cout << "Dealer Wins!!" << std::endl;
}

bool Game::getDraw() {
    return _draw;
}

bool Game::getWin() {
    return _win;
}

void Game::setWin() {
    _win = true;
}

void Game::setDraw() {
    _draw = true;
}

void Game::start() {
    cardDeck = new CardDeck();
    cardDeck->createDeck();
    while (_playAgain) {
        runGame();
        playAgain();
        cardDeck->resetDeck();
    }
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
