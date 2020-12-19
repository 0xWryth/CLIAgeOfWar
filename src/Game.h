#ifndef CLIAGEOFWAR_GAME_H
#define CLIAGEOFWAR_GAME_H

#include "Console.h"
#include "Grid.h"

class Game {
private:
    int _maxTurnLimit;
    Console _console;
    Grid* _grid = nullptr;
public:
    Game(const int gridSize = 12, const int maxTurnLimit = 100);
    void turn();
};


#endif //CLIAGEOFWAR_GAME_H
