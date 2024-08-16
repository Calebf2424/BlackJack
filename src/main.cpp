#include <iostream>

int main() {
    Game* game = new Game();
    game->start();
    game->runGame();
    game->quit();
    return 0;
}

