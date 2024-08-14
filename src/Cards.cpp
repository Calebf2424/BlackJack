#include "Cards.h"

//card class

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

CardDeck::CardDeck~() {
  for (Card* card : deck) {
    delete card;
  }
}
