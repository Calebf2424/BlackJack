#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

class Card {
 public:
    Card(char s, int v) : _suit(s), _value(v) {}
    void displayCardInfo();
    char getSuit();
    int getValue();

 private:
    char _suit;
    int _value;
};

class CardDeck {
 public:
    CardDeck() : deck(52) {};
    void createDeck();
    void shuffleDeck(std::vector<Card*>& deck);
    Card* drawCard(std::vector<Card*>& deck);
    void addToDeck(std::vector<Card*>& deck, std::vector<Card*>& hand);
    void resetDeck(std::vector<Card*>& deck, std::vector<Card*>& hand1, std::vector<Card*>& hand2);
    ~CardDeck();
 private:
    std::vector<Card*> deck;
    std::vector<Card*> dealer;
    std::vector<Card*> player;
};




#endif // CARDS_H
