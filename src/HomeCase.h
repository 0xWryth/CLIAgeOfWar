#ifndef CLIAGEOFWAR_HOMECASE_H
#define CLIAGEOFWAR_HOMECASE_H

/**
 * \file HomeCase.h
 * \brief Projet CLIAgeOfWar : classe HomeCase.
 * \version 0.1
 */
#include "GridCase.h"
#include "Health.h"
#include "Player.h"

/**
 * \class HomeCase
 * \brief classe representant la case servant de base à un joueur.
 *
 * La classe gère l'initialisation et le stockage des paramètres d'une base.
 */
class HomeCase : public GridCase, public Health {
public:
    /**
     * \brief Constructeur de la classe HomeCase
     * \param position Entier représentant la position occupée par la base sur le plateau de jeu.
     */
    HomeCase(int position);
};


#endif //CLIAGEOFWAR_HOMECASE_H
