#ifndef GAME_H
#define GAME_H
#include "Cards.h"

class Game {
 public:
    Game() : _win(false);
    ~Game();
    void start();
    void clearScreen();
    void playAgain();
    void runGame();
    void setWin();
    void setDraw();
    void calculateWinner();
    void quit();
    char handleInputYN();
    //render();

 private:
    CardDeck* cardDeck;
    bool _win;
    bool _draw;
    bool _playAgain;
};


#endif //GAME_H
