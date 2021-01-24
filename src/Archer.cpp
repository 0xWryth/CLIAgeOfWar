#include "Archer.h"

std::string Archer::getName(bool isShort) {
    return isShort ? "A" : "Archer";
}

Archer::Archer(Player* player) {
    _cost = 12;

    _initialHealth = 8;
    _currentHealth = 8;

    _damage = 3;

    std::vector<std::vector<int>> _reach{{ 1 },
                                         { 2 },
                                         { 3 } };

    _actions[1] = Action::Attack;
    _actions[2] = Action::None;
    _actions[3] = Action::MoveForward;

    _owner = player;
}

Archer::~Archer() {
    for (size_t i=0; i < _reach.size(); i++)
        _reach[i].clear();
    _reach.clear();

    // The _owner object has incomplete class type at this point..
    // delete _owner;
}
