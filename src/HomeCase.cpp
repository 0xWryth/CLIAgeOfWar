#include "HomeCase.h"

HomeCase::HomeCase(int position) : GridCase(position) {
	_initialHealth = 100;
    _currentHealth = 100;
}

bool HomeCase::suffersAttack(int damage) {
    if (this->isEmpty()) {
        this->removeHealth(damage);

        if (this->getCurrentHealth() <= 0) {
            return true;  // base is dead
        }

        return false;  // base is not dead
    } else {
        return GridCase::suffersAttack(damage);
    }
}