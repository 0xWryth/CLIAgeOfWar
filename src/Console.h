#ifndef CLIAGEOFWAR_CONSOLE_H
#define CLIAGEOFWAR_CONSOLE_H

/**
 * \file Console.h
 * \brief Projet CLIAgeOfWar : classe Console.
 * \version 0.1
 */

#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include "Panel.h"

/**
 * \class Console
 * \brief classe representant la sortie standard/l'affichage de la partie
 *
 * La classe gère l'affichage du plateau de jeu sur la sortie standard.
 */
class Console {
    std::map<Panel,std::vector<std::string>> _panels;
    int getMaxChar() const;
public:
    /**
     * \brief Constructeur de la classe Console
     */
    Console();

    /**
     * \fn addToPanel
     * \brief Fonction qui place une chaine de caractère donnée à une position donnée.
     * \param toAppend Chaine de caractère à afficher
     * \param position Panel correspondant à la position à disposer \p toAppend
     */
    void addToPanel(const std::string toAppend, Panel position);

    /**
     * \fn display
     * \brief Fonction en charge de l'affichage du plateau de jeu.
     */
    void display() const;

    /**
     * \fn clear
     * \brief Fonction en charge de la réinitialisation de l'affichage.
     */
    void clear();

    /**
     * \fn prompt
     * \brief Fonction qui engage l'utilisateur à renseigner une valeur dans l'entrée standard.
     * \param message Chaine de caractère correspondant au texte guidant l'utilisateur.
     * \param ignore Booléen optionnel indiquant que la valeur entrée n'a pas d'importance.
     * \return Valeur entrée par l'utilisateur (sous forme de chaine de caractère).
     */
    std::string prompt(std::string message, bool ignore = false) const;
};


#endif //CLIAGEOFWAR_CONSOLE_H