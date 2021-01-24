#ifndef CLIAGEOFWAR_GAME_H
#define CLIAGEOFWAR_GAME_H

/**
 * \file Game.h
 * \brief Projet CLIAgeOfWar : classe Game.
 * \version 0.1
 */

#include "Grid.h"
#include "Console.h"
#include "Player.h"
class Grid;

/**
 * \class Game
 * \brief classe representant une partie de CLIAgeOfWar
 *
 * La classe gère l'initialisation du jeu, les phases de tour-à-tour, l'affichage du
 * status des joueurs et le stockage des informations relatives à la partie courante.
 */
class Game {
private:
    int _maxTurnLimit;
    int _earnings;
    int _currentTurn;
    Console _console;
    Grid* _grid = nullptr;
    Player* _p1 = nullptr;
    Player* _p2 = nullptr;
    std::string _consoleHeader;
    void initializeGame(int gridSize);
    void displayPlayer();
public:
    /**
     * \brief Constructeur de la classe Game
     * \param gridSize  Entier représentant la taille du plateau de jeu (12 cases par défaut).
     * \param maxTurnLimit  Entier représentant un nombre de tour maximum (100 par défaut).
     * \param earnings  Entier représentant le nombre de pièces reçues par le joueur à chaque début de tour (8 cases par défaut).
     */
    Game(const int gridSize = 12, const int maxTurnLimit = 100, const int earnings = 8);

    /**
     * \fn turn
     * \brief Fonction en charge de la gestion du tour-par-tour.
     */
    void turn();

    /**
     * \fn play
     * \brief Tour de jeu d'un joueur.
     * \param une instance de Player représentant le joueur qui joue.
     */
    void play(Player* p);

    /**
     * \fn resolveActions
     * \brief Phases de résolution des actions 1, 2 et 3 du joueur \p p
     * \param une instance de Player représentant le joueur qui joue.
     */
    void resolveActions(Player* p);

    const std::pair<Player, Player> &getPlayers() const;

    Console &getConsole();
};


#endif //CLIAGEOFWAR_GAME_H
