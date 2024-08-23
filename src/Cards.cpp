#include "Cards.h"

//card class
std::string Card::getSuit() {
    switch(_suit) {
        case 'H': return "\u2665"; // ♥
        case 'D': return "\u2666"; // ♦
        case 'S': return "\u2660"; // ♠
        case 'C': return "\u2663"; // ♣
        default: return std::string(1, _suit);
    }
}

int Card::getValue() {
    return _value;
}

#include <iomanip>

void Card::displayCardInfo() {
    std::string suit = getSuit();
    int value = getValue();
    std::string displayValue;

    if(value == 1) {
        displayValue = "A";
    }
    else if(value == 11) {
        displayValue = "J";
    }
    else if (value == 12) {
        displayValue = "Q";
    }
    else if (value == 13) {
        displayValue = "K";
    } else {
        displayValue = std::to_string(value);
    }

    std::cout << std::setw(2) << displayValue << suit << " ";
}

//deck class
void CardDeck::createDeck() {
  char suits[] = {'H', 'D', 'S', 'C'};
  int index = 0;
  for (char suit : suits) {
    for (int value = 1; value <= 13; value++) {
      deck[index++] = new Card(suit, value);
    }
  }
}

void CardDeck::shuffleDeck() {
    auto seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count() & 0xFFFFFFFF);
    std::default_random_engine engine(seed);
    std::shuffle(deck.begin(), deck.end(), engine);
}

Card* CardDeck::drawCard() {
    Card* card = deck[0];
    deck.erase(deck.begin());
    return card;
}

void CardDeck::addToPlayerDeck() {
    Card* card = drawCard();
    updatePlayerScore(card);
    player.push_back(card);
}

void CardDeck::addToDealerDeck() {
    Card* card = drawCard();
    updateDealerScore(card);
    dealer.push_back(card);
}

void CardDeck::resetDeck() {
    for (Card* card : dealer) {
        deck.push_back(card);
    }
    for (Card* card : player) {
        deck.push_back(card);
    }
    player.clear();
    dealer.clear();

    _dealerScore = 0;
    _playerScore = 0;
    _dealerAces = 0;
    _playerAces = 0;
}

CardDeck::~CardDeck() {
  for (Card* card : deck) {
    delete card;
  }
}

void CardDeck::updateBoard() {
    std::cout << "Dealer:" << std::endl;
    for (Card* card : dealer) {
        card->displayCardInfo();
    }
    std::cout << std::endl << std::endl;
    std::cout << "Player:" << std::endl;
    for (Card* cardP : player) {
        cardP->displayCardInfo();
    }
    std::cout << std::endl << std::endl;
}


int CardDeck::getDealerScore() {
    return _dealerScore;
}

int CardDeck::getPlayerScore() {
    return _playerScore;
}

void CardDeck::updateDealerScore(Card* card) {
    int toAdd = card->getValue();
    if (toAdd == 1) {
        _dealerAces++;
        toAdd = 11;
    }
    else if (toAdd == 11 || toAdd == 12 || toAdd == 13) {
        toAdd = 10;
    }
    _dealerScore += toAdd;
    while (_dealerScore > 21 && _dealerAces > 0) {
        _dealerScore -= 10;
        _dealerAces--;
    }
}

void CardDeck::updatePlayerScore(Card* card) {
    int toAdd = card->getValue();
    if (toAdd == 1) {
        _playerAces++;
        toAdd = 11;
    }
    else if (toAdd == 11 || toAdd == 12 || toAdd == 13) {
        toAdd = 10;
    }
    _playerScore += toAdd;
    while (_playerScore > 21 && _playerAces > 0) {
        _playerScore -= 10;
        _playerAces--;
    }
}

void CardDeck::hasDealerBust() {
    _dealerBust = _dealerScore > 21;
}

void CardDeck::hasPlayerBust() {
    _playerBust = _playerScore > 21;
}

bool CardDeck::getHasDealerBust() {
    return _dealerBust;
}

bool CardDeck::getHasPlayerBust() {
    return _playerBust;
}

bool CardDeck::dealerBlackJack() {
    if (_dealerScore == 21 && dealer.size() == 2) return true;
    return false;
}

bool CardDeck::playerBlackJack() {
    if (_playerScore == 21 && player.size() == 2) return true;
    return false;
}

