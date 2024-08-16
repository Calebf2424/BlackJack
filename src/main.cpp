#include <iostream>
#include "Game.h"
#include "Cards.h"

int main() {
    Game* game = new Game();
    game->start();
    game->runGame();
    game->quit();

    game = nullptr;
    return 0;
}

