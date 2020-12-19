#ifndef CLIAGEOFWAR_GAME_H
#define CLIAGEOFWAR_GAME_H

#include "Console.h"
#include "Grid.h"
#include "Player.h"

class Game {
private:
    int _maxTurnLimit;
    int _earnings;
    Console _console;
    Grid* _grid = nullptr;
    std::pair<Player, Player> _players;
    std::string _consoleHeader;
    void initializeGame();
    void displayPlayer();
public:
    Game(const int gridSize = 12, const int maxTurnLimit = 100, const int earnings = 8);
    void turn();
};


#endif //CLIAGEOFWAR_GAME_H
