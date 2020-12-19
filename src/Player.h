#ifndef CLIAGEOFWAR_PLAYER_H
#define CLIAGEOFWAR_PLAYER_H

#include <iostream>
#include "Console.h"

class Player {
private:
    std::string _playerName;
    int _playerId;
    static int _playerNumber;
    int _coins;
public:
    Player();
    std::string displayStr();
    void initialize(const Console console);
};


#endif //CLIAGEOFWAR_PLAYER_H
