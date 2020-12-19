#ifndef CLIAGEOFWAR_PLAYER_H
#define CLIAGEOFWAR_PLAYER_H

#include <iostream>

class Player {
private:
    std::string _playerName;
    int _playerId;
    static int _playerNumber;
public:
    Player();
    void display();
};


#endif //CLIAGEOFWAR_PLAYER_H
