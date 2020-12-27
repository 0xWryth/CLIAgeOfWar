#ifndef CLIAGEOFWAR_PLAYER_H
#define CLIAGEOFWAR_PLAYER_H

/**
 * \file Player.h
 * \brief Projet CLIAgeOfWar : classe Player.
 * \version 0.1
 */

#include <iostream>
#include "Console.h"

/**
 * \class Player
 * \brief classe representant un des joueurs
 *
 * La classe gère l'initialisation, l'affichage et le stockage des informations liées au Joueur.
 */
class Player {
private:
    std::string _playerName;
    int _playerId;
    static int _playerNumber;
    int _coins;
public:
    /**
     * \brief Constructeur de la classe Player
     */
    Player();

    /**
     * \fn displayStr
     * \brief Fonction qui renvoie les informations relatives au joueur (nom, pièces..)
     * \return une chaine de caractères représentant l'état du joueur.
     */
    std::string displayStr();

    /**
     * \fn displayStr
     * \brief Fonction qui enregistre le nom du Joueur entré par l'utilisateur via la CLI.
     * \param un objet Console correspondant à l'instance courante de Console du jeu.
     */
    void initialize(const Console console);
};


#endif //CLIAGEOFWAR_PLAYER_H
