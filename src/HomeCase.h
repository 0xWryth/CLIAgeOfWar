#ifndef CLIAGEOFWAR_HOMECASE_H
#define CLIAGEOFWAR_HOMECASE_H

#include "GridCase.h"
#include "Health.h"
#include "Player.h"

class HomeCase : public GridCase, public Health {
private:
public:
    HomeCase(int position);
};


#endif //CLIAGEOFWAR_HOMECASE_H
