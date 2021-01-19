#ifndef CLIAGEOFWAR_CATAPULT_H
#define CLIAGEOFWAR_CATAPULT_H

#include "Troup.h"

class Catapult : public Troup {
public:
    std::string getName(bool isShort) override;
};


#endif //CLIAGEOFWAR_CATAPULT_H
