#ifndef CLIAGEOFWAR_ARCHER_H
#define CLIAGEOFWAR_ARCHER_H

#include "Troup.h"

class Archer : public Troup {
public:
    std::string getName(bool isShort) override;
};


#endif //CLIAGEOFWAR_ARCHER_H
