#ifndef CLIAGEOFWAR_CATAPULT_H
#define CLIAGEOFWAR_CATAPULT_H

/**
 * \file Catapult.h
 * \brief Projet CLIAgeOfWar : classe Catapult.
 * \version 0.1
 */

#include "Troup.h"

/**
 * \class Catapult
 * \brief classe representant une unité de type Catapult
 *
 * La classe initialise et stocke les caractéristiques d'une Catapult.
 */
class Catapult : public Troup {

public:
    /**
     * \brief Constructeur de la classe Catapult
     */
    Catapult();
    /**
     * \brief Destructeur de la classe Catapult
     */
    ~Catapult();

    std::string getName(bool isShort) override;
};


#endif //CLIAGEOFWAR_CATAPULT_H
