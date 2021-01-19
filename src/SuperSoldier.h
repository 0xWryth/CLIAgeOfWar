#ifndef CLIAGEOFWAR_SUPERSOLDIER_H
#define CLIAGEOFWAR_SUPERSOLDIER_H

#include "Troup.h"

class SuperSoldier : public Troup {
public:
    std::string getName(bool isShort) override;
};


#endif //CLIAGEOFWAR_SUPERSOLDIER_H
