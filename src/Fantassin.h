#ifndef CLIAGEOFWAR_FANTASSIN_H
#define CLIAGEOFWAR_FANTASSIN_H

#include "Troup.h"

class Fantassin : public Troup {
public:
    std::string getName(bool isShort) override;
};


#endif //CLIAGEOFWAR_FANTASSIN_H
