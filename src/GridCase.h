#ifndef CLIAGEOFWAR_GRIDCASE_H
#define CLIAGEOFWAR_GRIDCASE_H

/**
 * \file GridCase.h
 * \brief Projet CLIAgeOfWar : classe GridCase.
 * \version 0.1
 */

#include <vector>
#include "Troup.h"
#include "Player.h"

/**
 * \class GridCase
 * \brief classe representant une case du plateau de jeu
 *
 * La classe stocke sa position et la possible unité placée dessus.
 */
class GridCase {
    int _position;
    Troup* _unit;
    bool _filled;

public:
    /**
     * \brief Constructeur de la classe GridCase
     * \param position Entier représentant la position occupée par la case sur le plateau de jeu.
     */
    GridCase(int position = 0);

    /**
     * \fn placeUnit
     * \brief Fonction qui place si possible l'unité souhaitée sur la case.
     * \param unit Pointeur sur l'unité à placer.
     * \return true si l'opération a réussi, false sinon.
     */
    bool placeUnit(Troup* unit);

    /**
     * \fn isEmpty
     * \brief Renvoie l'état d'occupation de la case.
     * \return true si la case est vide, false sinon.
     */
    bool isEmpty();

    /**
     * \fn getTroupName
     * \brief Renvoie le nom de l'unité qui occupe la case.
     * \param isShort Booléen optionnel permettant d'obtenir le nom réduit à un caractère.
     * \return Une chaine de caractère correspondant au type de l'unité placée sur la case.
     */
    std::string getTroupName(bool isShort = false);

    Troup *getUnit() const;

    Player* getUnitOwner() { return _unit->getOwner(); };

    Action getUnitAction(int phase) { return _unit->getAction(phase); }

    int getPosition() const;

    void transferTroupToCase(GridCase* gridCase);
};

#endif //CLIAGEOFWAR_GRIDCASE_H
