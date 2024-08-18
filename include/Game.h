#ifndef GAME_H
#define GAME_H

class Game {
 public:
    Game();
    ~Game();
    void start();
    void playAgain();
    void runGame();
    void quit();
    char handleInputYN();
    void updateBoard(std::vector<Card*>&, std::vector<Card*>&);
    //render();

 private:
    CardDeck* deck;
    bool _playAgain;
    int _playerScore;
    int _dealerScore;
};


#endif //GAME_H
