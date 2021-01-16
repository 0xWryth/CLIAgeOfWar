#ifndef CLIAGEOFWAR_GRIDCASE_H
#define CLIAGEOFWAR_GRIDCASE_H

/**
 * \file GridCase.h
 * \brief Projet CLIAgeOfWar : classe GridCase.
 * \version 0.1
 */

#include <vector>
#include "Troup.h"

/**
 * \class GridCase
 * \brief classe representant une case du plateau de jeu
 *
 * La classe stocke sa position et la possible unité placée dessus.
 */
class GridCase {
private:
    int _position;
    Troup* _unit = nullptr;
public:
    GridCase(int position = 0);

    bool placeUnit(Troup* unit);
    bool isEmpty() { return _unit == nullptr; };
};

#endif //CLIAGEOFWAR_GRIDCASE_H
