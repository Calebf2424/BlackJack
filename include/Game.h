#ifndef GAME_H
#define GAME_H
#include "Cards.h"

class Game {
 public:
    Game();
    ~Game();
    void start();
    void clearScreen();
    void playAgain();
    void runGame();
    void quit();
    char handleInputYN();
    //render();

 private:
    CardDeck* cardDeck;
    bool _win;
    bool _playAgain;
};


#endif //GAME_H
