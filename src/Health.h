#ifndef CLIAGEOFWAR_HEALTH_H
#define CLIAGEOFWAR_HEALTH_H

/**
 * \file Health.h
 * \brief Projet CLIAgeOfWar : classe Health.
 * \version 0.1
 */

#include <algorithm>

// TODO: Make Health class abstract

/**
 * \class Health
 * \brief classe representant l'etat de sante de quelque chose.
 *
 * La classe stocke et gère des points de vie.
 */
class Health {
protected:
    int _initialHealth;
    int _currentHealth;
public:
    /**
     * \fn getCurrentHealth
     * \brief Retourne le nombre de points de vie actuel.
     */
    int getCurrentHealth() const { return _currentHealth; };

    /* TODO : manipulate current health ? add, remove (+ verifications) */

    /**
     * \fn removeHealth
     * \brief Retranche le nombre de points de vie indiqué en paramètre.
     * \param damage Entier correspondant au dégats infligés.
     */
    void removeHealth(int damage);
};


#endif //CLIAGEOFWAR_HEALTH_H
