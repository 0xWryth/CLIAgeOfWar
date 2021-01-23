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
private:
protected:
    int _cost;
    int _damage;
    std::vector<std::vector<int>> _reach;
    std::map<int, Action> _actions;

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

    virtual std::string getName(bool isShort = false) = 0;
};


#endif //CLIAGEOFWAR_TROUP_H
