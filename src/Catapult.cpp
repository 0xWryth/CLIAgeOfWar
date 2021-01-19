#include "Catapult.h"

std::string Catapult::getName(bool isShort) {
    return isShort ? "C" : "Catapult";
}

Catapult::Catapult() {
    _cost = 20;

    _initialHealth = 12;
    _currentHealth = 12;

    _damage = 6;

    std::vector<std::vector<int>> _reach{{ 2, 3 },
                                         { 3, 4 } };
}

Catapult::~Catapult() {
    for (size_t i=0; i < _reach.size(); i++)
        _reach[i].clear();
    _reach.clear();
}