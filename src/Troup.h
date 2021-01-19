#ifndef CLIAGEOFWAR_TROUP_H
#define CLIAGEOFWAR_TROUP_H


#include <string>
#include "Health.h"

// TODO: Make Troup class abstract

class Troup : public Health {
private:
    int _cost;
    int _damage;
    int** reach;
public:
    virtual std::string getName(bool isShort = false) = 0;
};


#endif //CLIAGEOFWAR_TROUP_H
