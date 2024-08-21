#include "Game.h"
#include "Cards.h"
#include <cctype>

Game::~Game() {
    if (cardDeck) delete cardDeck;
    }

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
        std::cout << "Hit? (Y/N): ";
        char choice = handleInputYN();
        if (choice == 'Y') {
            cardDeck->addToPlayerDeck();
            cardDeck->updateBoard();
            pScore = cardDeck->getPlayerScore();
            cardDeck->hasPlayerBust();
            bool playerBust = cardDeck->getHasPlayerBust();
            if (playerBust) {
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
        bool dealerBust = cardDeck->getHasDealerBust();
        if (dealerBust) {
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
    _playAgain = true;
    while (_playAgain) {
        runGame();
        playAgain();
        cardDeck->resetDeck();
    }
}

void Game::playAgain() {
    std::cout << "Play again? (Y/N): ";
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
        std::cin >> input;
        input = std::toupper(input);
        if (input == 'Y' || input == 'N') {
            valid = true;
        } else {
            std::cout << "Invalid input, enter Y or N:" << std::endl;
        }
    }
    return input;
}

void Game::clearScreen() {
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}
