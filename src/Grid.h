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
    Game* _game = nullptr;
    int _gridSize;
    std::vector<GridCase> _gridCases;
public:
    /**
     * \brief Constructeur de la classe Grid
     * \param game
     * \param gridSize  Entier représentant la taille du plateau de jeu.
     */
    Grid(const int gridSize, Game* game);
    void display();

    int getGridSize() const { return _gridSize; };

    void debug();
};


#endif //CLIAGEOFWAR_GRID_H
