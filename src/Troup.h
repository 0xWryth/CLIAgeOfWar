#ifndef CLIAGEOFWAR_TROUP_H
#define CLIAGEOFWAR_TROUP_H


#include "Health.h"

// TODO: Make Troup class abstract

class Troup : public Health {
private:
    int _cost;
    int _damage;
    int** reach;
};


#endif //CLIAGEOFWAR_TROUP_H
