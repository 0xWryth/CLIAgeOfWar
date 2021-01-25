#include "Catapult.h"

std::string Catapult::getName(bool isShort) {
    return isShort ? "C" : "Catapult";
}

Catapult::Catapult(Player* player) {
    _cost = 20;

    _initialHealth = 12;
    _currentHealth = 12;

    _damage = 6;

    std::vector<std::vector<int>> _reach{{ 2, 3 },
                                         { 3, 4 } };

    _actions[1] = Action::Attack;
    _actions[2] = Action::None;
    _actions[3] = Action::MoveForward;

    _owner = player;
}

Catapult::~Catapult() {
    for (size_t i=0; i < _reach.size(); i++)
        _reach[i].clear();
    _reach.clear();

    // The _owner object has incomplete class type at this point..
    // delete _owner;
}