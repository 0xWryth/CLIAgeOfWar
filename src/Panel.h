#ifndef CLIAGEOFWAR_PANEL_H
#define CLIAGEOFWAR_PANEL_H

/**
 * \file Panel.h
 * \brief Projet CLIAgeOfWar : classe Panel.
 * \version 0.1
 */

#include <initializer_list>

/**
 * \enum Panel
 * \brief enumeration representant les "positions d'affichage" possibles dans la sortie standard
 */
enum class Panel {
    Top,    /*!< affichage en haut */
    Left,   /*!< affichage à gauche */
    Right,  /*!< affichage à droite */
    Bottom  /*!< affichage en bas */
};

constexpr std::initializer_list<Panel> all_Panel = {Panel::Top, Panel::Left, Panel::Right, Panel::Bottom};

#endif //CLIAGEOFWAR_PANEL_H
