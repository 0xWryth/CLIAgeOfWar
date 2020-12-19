#ifndef CLIAGEOFWAR_HOMECASE_H
#define CLIAGEOFWAR_HOMECASE_H

#include "GridCase.h"
#include "Player.h"
#include "Health.h"

class HomeCase : public GridCase, public Health {
private:
    Player _owner;
};


#endif //CLIAGEOFWAR_HOMECASE_H
