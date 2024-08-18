#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

class Card {
 public:
    Card(char s, int v) : _suit(s), _value(v){}
    void displayCardInfo();
    char getSuit();
    int getValue();

 private:
    char _suit;
    int _value;
};

class CardDeck {
 public:
    CardDeck() : deck(52), _playerScore(0), _dealerScore(0) {};
    void createDeck();
    void shuffleDeck();
    Card* drawCard();
    void addToPlayerDeck();
    void addToDealerDeck();
    void resetDeck();
    void updateBoard();
    int getPlayerScore();
    int getDealerScore();
    void updatePlayerScore(Card*);
    void updateDealerScore(Card*);
    ~CardDeck();
 private:
    std::vector<Card*> deck;
    std::vector<Card*> dealer;
    std::vector<Card*> player;
    int _playerScore;
    int _dealerScore;
};




#endif // CARDS_H
