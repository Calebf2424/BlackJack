#include "Cards.h"

//card class
char Card::getSuit() {
    return _suit;
}

int Card::getValue() {
    return _value;
}

void Card::displayCardInfo() {
    char suit = getSuit();
    int value = getValue();
    if(value == 1) {
        std::cout << "A" << suit << " ";
        return;
    }
    else if(value == 11) {
        std::cout << "J" << suit << " ";
    }
    else if (value == 12) {
        std::cout << "Q" << suit << " ";
    }
    else if (value == 13) {
        std::cout << "K" << suit << " ";
    } else {
        std::cout << value << suit << " ";
    }
    
}
//deck class
void CardDeck::createDeck() {
  char suits[] = {'H', 'D', 'S', 'C'};
  int index = 0;
  for (char suit : suits) {
    for (int value = 1; value <= 13; value++) {
      deck[index] = new Card(suit, value);
    }
  }
}

void CardDeck::shuffleDeck() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
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
    player.push_back(card);
}

void CardDeck::addToDealerDeck() {
    Card* card = drawCard();
    
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
}

CardDeck::~CardDeck() {
  for (Card* card : deck) {
    delete card;
  }
}

void CardDeck::updateBoard() {
    std::cout << "Dealer" << std::endl;
    for (Card* card : dealer) {
        card->displayCardInfo();
    }
    std::cout << "\n\n\n\n\n\n";
    std::cout << "Player:" << std::endl;
    for (Card* cardP : player) {
        cardP->displayCardInfo();
    }
}

int CardDeck::getDealerScore() {
    return _dealerScore;
}

int CardDeck::getPlayerScore() {
    return _playerScore;
}

void CardDeck::updateDealerScore(Card* card) {
    int toAdd = card->getValue();
    //need to figure out choices for A = 1 vs A = 11
}

void CardDeck::updatePlayerScore(Card* card) {
    int toAdd = card->getValue();
    //need to figure out choices for A = 1 vs A = 11
}