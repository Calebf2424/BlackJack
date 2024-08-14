#include "Cards.h"

//card class
char Card::getSuit() {
    return _suit;
}

int Card::getValue() {
    return _value;
}

void Card::displayCardInfo() {
    char _suit = getSuit();
    int _value = getValue();
    if(value == 1) {
        std::cout << "A" << suit;
        return;
    }
    else if(value == 11) {
        std::cout << "J" << suit;
    }
    else if (value == 12) {
        std::cout << "Q" << suit;
    }
    else if (value == 13) {
        std::cout << "K" << suit;
    } else {
        std::cout << value << suit;
    }
    
}
//deck class
void CardDeck::createDeck() {
  char suits[] = {'H', 'D', 'S', 'C'};
  int index = 0;
  for (char suit : suits) {
    for (int value = 1; value <= 13; value++) {
      deck[index] = new card(suit, value);
    }
  }
}

void CardDeck::shuffleDeck(std::vector<Card*>& deck) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine engine(seed);
    std::shuffle(deck.begin(), deck.end(), engine);
}

Card* CardDeck::drawCard(std::vector<Card*>& deck) {
    Card* card = deck[0];
    deck.erase(deck.begin());
    return card;
}

void CardDeck::addToDeck(std::vector<Card*>& deck, std::vector<Card*>& hand) {
    Card* card = drawCard(deck);
    hand.push_back(card);
}

void CardDeck::resetDeck(std::vector<Card*>& deck, std::vector<Card*>& hand1, std::vector<Card*>& hand2) {
    for (Card* card : hand1) {
        deck.push_back(card);
    }
    for (Card* card : hand2) {
        deck.push_back(card);
    }
    hand1.clear();
    hand2.clear();
}

CardDeck::CardDeck~() {
  for (Card* card : deck) {
    delete card;
  }
}
