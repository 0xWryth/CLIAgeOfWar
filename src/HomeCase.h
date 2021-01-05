#ifndef CLIAGEOFWAR_HOMECASE_H
#define CLIAGEOFWAR_HOMECASE_H

#include "GridCase.h"
#include "Health.h"
#include "Player.h"

class HomeCase : public GridCase, public Health {
private:
    Player* _owner;
public:
    HomeCase(Player* owner, int position);
};


#endif //CLIAGEOFWAR_HOMECASE_H
