#ifndef CLIAGEOFWAR_FANTASSIN_H
#define CLIAGEOFWAR_FANTASSIN_H

/**
 * \file Fantassin.h
 * \brief Projet CLIAgeOfWar : classe Fantassin.
 * \version 0.1
 */

#include "Troup.h"

/**
 * \class Fantassin
 * \brief classe representant une unité de type Fantassin
 *
 * La classe initialise et stocke les caractéristiques d'un Fantassin.
 */
class Fantassin : public Troup {

public:
    /**
     * \brief Constructeur de la classe Fantassin
     */
    Fantassin();
    /**
     * \brief Destructeur de la classe Fantassin
     */
    ~Fantassin();

    std::string getName(bool isShort) override;
};


#endif //CLIAGEOFWAR_FANTASSIN_H
