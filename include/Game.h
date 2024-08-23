#ifndef GAME_H
#define GAME_H
#include "Cards.h"

class Game {
 public:
    Game() : cardDeck(nullptr), _win(false), _draw(false){};
    ~Game();
    void start();
    void clearScreen();
    void playAgain();
    void runGame();
    void setWin(bool);
    void setDrawTrue();
    void setDrawFalse();
    bool getWin();
    bool getDraw();
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
