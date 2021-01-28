/**
 * \file main.cpp
 * \brief Projet CLIAgeOfWar : méthode principale.
 * \version 0.1
 */

#include <iostream>
#include "Game.h"
#include<string>

int param(int argc, char *argv[], int number, int defaultValue) {
    if (argc >= number + 1) {
        int value = std::stoi(argv[number]);
        if (value < 0) {
            return defaultValue;
        }
        else {
            return value;
        }
    }
    else {
        return defaultValue;
    }
}

/**
 * \fn main
 * \brief Lance le jeu avec les paramètres par défaut.
 * \return Un entier 0 si la partie s'est terminée sans erreur.
 */
int main(int argc, char *argv[]) {
    int gameMode = param(argc, argv, 1, 0);
    if (gameMode == 1) {
        std::cout << "Multiplayer is not implemented yet." << std::endl;
        return -1;
    }
    else if (gameMode > 1) {
        std::cout << "Unknown game mode." << std::endl;
        return -2;
    }

    int gridSize = param(argc, argv, 2, 12);
    if (gridSize < 5) {
        std::cout << "Grid size must at least be of 5 cases." << std::endl;
        return -3;
    }
    else if (gridSize >= 20) {
        std::cout << "Grid size cannot be greater than 20 cases." << std::endl;
        return -4;
    }

    int maxTurnLimit = param(argc, argv, 3, 10);
    int earning = param(argc, argv, 4, 8);
    if (earning == 0) {
        std::cout << "Earning cannot be 0." << std::endl;
        return -5;
    }
    
    Game game(gridSize, maxTurnLimit, earning);

    return 0;
}