#ifndef CLIAGEOFWAR_SUPERSOLDIER_H
#define CLIAGEOFWAR_SUPERSOLDIER_H

/**
 * \file SuperSoldier.h
 * \brief Projet CLIAgeOfWar : classe SuperSoldier.
 * \version 0.1
 */

#include "Troup.h"

/**
 * \class SuperSoldier
 * \brief classe representant une unité de type SuperSoldat
 *
 * La classe stocke ... du SuperSoldat.
 */
class SuperSoldier : public Troup {

    /* Is SuperSoldier :
            - a totally different Troup ?
            - a specification of Fantassin ?
            - just a boolean in Fantassin triggered by a "promote()" method ?
    */

public:
    std::string getName(bool isShort) override;
};


#endif //CLIAGEOFWAR_SUPERSOLDIER_H
