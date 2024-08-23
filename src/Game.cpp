#include "Game.h"
#include "Cards.h"
#include <cctype>

Game::~Game() {
    if (cardDeck) delete cardDeck;
    }

void Game::runGame() {
    std::cout << "Black Jack\n\n";
    cardDeck->shuffleDeck();
    cardDeck->addToDealerDeck();
    cardDeck->addToPlayerDeck();
    cardDeck->addToPlayerDeck();
    clearScreen();
    cardDeck->updateBoard();

    // Check for initial Blackjacks
    if (cardDeck->playerBlackJack()) {
        setWin(true);
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
            clearScreen();
            cardDeck->updateBoard();
            pScore = cardDeck->getPlayerScore();
            cardDeck->hasPlayerBust();
            if (cardDeck->getHasPlayerBust()) {
                setWin(false);  // Player has busted, they lose
                calculateWinner();
                return;
            }
        } else {
            break;
        }
    }

    // Dealer's turn
    cardDeck->addToDealerDeck();
    clearScreen();
    cardDeck->updateBoard();
    if (cardDeck->dealerBlackJack()) {
        setWin(false); // Dealer has blackjack, player loses
        calculateWinner();
        return;
    }
    int dScore = cardDeck->getDealerScore();
    while (dScore < 17) {
        cardDeck->addToDealerDeck();
        clearScreen();
        cardDeck->updateBoard();
        dScore = cardDeck->getDealerScore();
        cardDeck->hasDealerBust();
        if (cardDeck->getHasDealerBust()) {
            setWin(true);  // Dealer has busted, player wins
            calculateWinner();
            return;
        }
    }

    // Determine the outcome
    if (cardDeck->getPlayerScore() > cardDeck->getDealerScore()) {
        setWin(true);
    } else if (cardDeck->getPlayerScore() == cardDeck->getDealerScore()) {
        setDrawTrue();
    } else {
        setWin(false); // Dealer wins if the scores are not equal and player has not already won
    }
    calculateWinner();
}

void Game::calculateWinner() {
    if (getDraw()) {
        std::cout << "Game is a Draw !!" << std::endl;
        std::cout << "Dealer Score: " << cardDeck->getDealerScore() << "Player Score: " << cardDeck->getPlayerScore() << std::endl;
        setDrawFalse();
        return;
    }
    bool win = getWin();
    win ? std::cout << "Player Wins!!" << std::endl : std::cout << "Dealer Wins!!" << std::endl;
    std::cout << "Dealer Score: " << cardDeck->getDealerScore() << "Player Score: " << cardDeck->getPlayerScore() << std::endl;
}

void Game::setWin(bool win) {
    _win = win;
}

bool Game::getDraw() {
    return _draw;
}

bool Game::getWin() {
    return _win;
}


void Game::setDrawTrue() {
    _draw = true;
}

void Game::setDrawFalse() {
    _draw = false;
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
