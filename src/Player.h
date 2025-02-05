#ifndef CLIAGEOFWAR_PLAYER_H
#define CLIAGEOFWAR_PLAYER_H

/**
 * \file Player.h
 * \brief Projet CLIAgeOfWar : classe Player.
 * \version 0.1
 */

#include "Console.h"
#include "Troup.h"

class GridCase;
class HomeCase;

/**
 * \class Player
 * \brief classe representant un des joueurs
 *
 * La classe gère l'initialisation, l'affichage et le stockage des informations liées au Joueur.
 */
class Player {
    std::string _playerName;
    int _playerId;
    int _coins;
    static int _playerNumber;
    HomeCase& _homeCase;

public:
    /**
     * \brief Constructeur de la classe Player
     */
    Player(HomeCase &homeCase);

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

    std::string getFirstLetter();

    /**
     * \fn getName
     * \brief Retourne la chaine de caractère correspondant au nom du joueur.
     */
    std::string getName() const { return _playerName; };

    /**
     * \fn incrementCoins
     * \brief Ajoute un nombre \p coins aux pièces d'or du joueur.
     * \param coins un entier représentant le nombre de pièces à ajouter à la cagnotte du joueur.
     */
    void incrementCoins(int coins) { if(coins > 0) _coins += coins; };

    /**
     * \fn decrementCoins
     * \brief Décrémente de \p coins pièces d'or la cagnotte du joueur.
     * \param coins un entier représentant le nombre de pièces à enlever de la banque du joueur.
     */
    void decrementCoins(int coins) { if(coins > 0) _coins -= coins; };

    /**
     * \fn isKO
     * \brief Renvoie true si la base du joueur a été détruite.
     */
    bool isKO();

    /**
     * \fn canPlaceTroup
     * \brief Fonction permettant de vérifier si la base du joueur n'est pas déjà occupée.
     * \return true si l'emplacement est vide, false sinon.
     */
    bool canPlaceTroup();

    /**
     * \fn placeTroupOnHomeCase
     * \brief Fonction qui place une unité sur la base du joueur.
     * \param troup Pointeur sur l'unité à placer.
     */
    bool placeTroupOnHomeCase(Troup* troup);

    HomeCase& getHomeCase();

    int getCoins() const;

    // Don't seems to be useful :
    // inline bool operator==(const X& lhs, const X& rhs){ return ...; }
};


#endif //CLIAGEOFWAR_PLAYER_H
