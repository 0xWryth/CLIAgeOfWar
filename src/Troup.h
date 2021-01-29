#ifndef CLIAGEOFWAR_TROUP_H
#define CLIAGEOFWAR_TROUP_H

/**
 * \file Troup.h
 * \brief Projet CLIAgeOfWar : classe Troup.
 * \version 0.1
 */

#include <string>
#include "Health.h"
#include <vector>
#include <map>

class Player;
class GridCase;
class HomeCase;
class Grid;

/**
 * \enum Action
 * \brief enumeration representant les différentes action possibles pour une unité
 */
enum class Action {
    Attack,     /*!< attaquer */
    MoveForward,/*!< avancer */
    None        /*!< ne rien faire */
};

/**
 * \class Troup
 * \brief classe representant une unité (de "type général")
 *
 * La classe stocke les caractéristiques d'une unité.
 */
class Troup : public Health {
protected:
    int _cost;
    int _damage;
    std::vector<std::vector<int>> _reach;
    std::map<int, Action> _actions;
    Player* _owner;

public:
    /**
     * \fn getCost
     * \brief Retourne le nombre de pièces d'or nécessaire pour acheter l'unité.
     */
    int getCost() { return _cost; };

    /**
     * \fn getDamage
     * \brief Retourne en entier correspondnat aux dommages infligés par l'unité.
     */
    int getDamage() { return _damage; };

    /**
     * \fn getName
     * \brief Fonction abstraite censée renvoyer le nom de l'unité qui occupe la case.
     * \param isShort Booléen optionnel permettant d'obtenir le nom réduit à un caractère.
     * \return Une chaine de caractère correspondant au type de l'unité placée sur la case.
     */
    virtual std::string getName(bool isShort = false) = 0;

    Player* getOwner() { return _owner; };

    Action getAction(int phase) { return _actions.at(phase); };

    /**
     * \fn canAttack
     * \brief Fonction abstraite censée renvoyer le nom de l'unité qui occupe la case.
     * \param grid Pointeur vers le plateau de jeu.
     * \param casePosition
     * \param moveDirection
     * \return Un pointeur vers la case à cibler.
     */
    GridCase* canAttack(Grid* grid, int casePosition, int moveDirection);

    /**
     * \fn attack
     * \brief Fonction abstraite censée renvoyer le nom de l'unité qui occupe la case.
     * \param grid Pointeur vers le plateau de jeu.
     * \param target Un pointeur vers la case à cibler.
     * \return Une chaine de caractère correspondant au type de l'unité placée sur la case.
     */
    std::string attack(Grid* grid, GridCase* target);
};


#endif //CLIAGEOFWAR_TROUP_H
