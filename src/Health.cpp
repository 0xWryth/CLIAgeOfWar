#include "Health.h"

void Health::removeHealth(int damage) {
    _currentHealth = std::max(0, _currentHealth - damage);
}