#ifndef CLIAGEOFWAR_ARCHER_H
#define CLIAGEOFWAR_ARCHER_H

/**
 * \file Archer.h
 * \brief Projet CLIAgeOfWar : classe Archer.
 * \version 0.1
 */

#include "Troup.h"

/**
 * \class Archer
 * \brief classe representant une unité de type Archer
 *
 * La classe initialise et stocke les caractéristiques d'un Archer.
 */
class Archer : public Troup {

public:
    /**
     * \brief Constructeur de la classe Archer
     */
    Archer();
    /**
     * \brief Destructeur de la classe Archer
     */
    ~Archer();

    std::string getName(bool isShort) override;
};


#endif //CLIAGEOFWAR_ARCHER_H
