#ifndef CLIAGEOFWAR_GRID_H
#define CLIAGEOFWAR_GRID_H

#include <string>

/**
 * \file Grid.h
 * \brief Projet CLIAgeOfWar : classe Grid.
 * \version 0.1
 */

#include "HomeCase.h"
#include "GridCase.h"
#include "Game.h"
class Game;

/**
 * \class Grid
 * \brief classe representant la grille du jeu
 *
 * La classe gère l'initialisation et le stockage des paramètres de la grille du jeu.
 */
class Grid {
private:
    int _gridSize;
    std::vector<GridCase*> _gridCases;
public:
    /**
     * \brief Constructeur de la classe Grid
     * \param gridSize Entier représentant la taille du plateau de jeu.
     * \param p1 Instance représentant le joueur 1.
     * \param p2 Instance représentant le joueur 2.
     */
    Grid(const int gridSize, Player& p1, Player& p2);

    /**
     * \fn display
     * \brief Fonction en charge de l'affichage de la grille. Positionne les cases et leurs contenus.
     * \param console Instance de Console correspondant à la sortie standard.
     * \param p1 Instance représentant le joueur 1.
     * \param p2 Instance représentant le joueur 2.
     */
    void display(Console& console, Player& p1, Player& p2);

    int getGridSize() const { return _gridSize; };

    void debug();
};


#endif //CLIAGEOFWAR_GRID_H
