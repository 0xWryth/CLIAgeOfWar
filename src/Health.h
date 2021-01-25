#ifndef CLIAGEOFWAR_HEALTH_H
#define CLIAGEOFWAR_HEALTH_H

// TODO: Make Health class abstract

class Health {
protected:
    int _initialHealth;
    int _currentHealth;
public:
    /* TODO : manipulate current health ? add, remove (+ verifications) */

    /**
     * \fn getCurrentHealth
     * \brief Retourne le nombre de points de vie actuel.
     */
    int getCurrentHealth() const { return _currentHealth; };
};


#endif //CLIAGEOFWAR_HEALTH_H
