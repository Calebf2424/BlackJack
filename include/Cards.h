#ifndef CARDS_H
#define CARDS_H
#include <utility>

class Card {
 public:
    Card(char s, int v) : suit(s), value(v) {}
    void displayCardInfo();
    char getSuit();
    int getValue();

 private:
    char suit;
    int value;
};

class CardDeck {
 public:
    cardDeck() : deck(52) {};
    void createDeck();
    void shuffleDeck();
    void playerDrawCard();
    void dealerDrawCard();
    void resetDeck();
    CardDeck~();
 private:
    std::vector<Card*> deck;
    std::vector<Card*> dealer;
    std::vector<Card*> player;
};




#endif // CARDS_H
