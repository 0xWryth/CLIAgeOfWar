#ifndef CLIAGEOFWAR_GRID_H
#define CLIAGEOFWAR_GRID_H

/**
 * \file Grid.h
 * \brief Projet CLIAgeOfWar : classe Grid.
 * \version 0.1
 */

/**
 * \class Grid
 * \brief classe representant la grille du jeu
 *
 * La classe gère l'initialisation et le stockage des paramètres de la grille du jeu.
 */
class Grid {
    int _gridSize;
public:
    /**
     * \brief Constructeur de la classe Grid
     * \param gridSize  Entier représentant la taille du plateau de jeu.
     */
    Grid(const int gridSize);
};


#endif //CLIAGEOFWAR_GRID_H
