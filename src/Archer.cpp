#include "Archer.h"

std::string Archer::getName(bool isShort) {
    return isShort ? "A" : "Archer";
}

Archer::Archer() {
    _cost = 12;

    _initialHealth = 8;
    _currentHealth = 8;

    _damage = 3;

    std::vector<std::vector<int>> _reach{{ 1 },
                                         { 2 },
                                         { 3 } };
}

Archer::~Archer() {
    for (size_t i=0; i < _reach.size(); i++)
        _reach[i].clear();
    _reach.clear();
}
