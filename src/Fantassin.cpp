#include "Fantassin.h"

std::string Fantassin::getName(bool isShort) {
    return isShort ? "F" : "Fantassin";
}

Fantassin::Fantassin(Player* player) {
    _cost = 10;

    _initialHealth = 10;
    _currentHealth = 10;

    _damage = 4;

    std::vector<std::vector<int>> _reach{{ 1 }};

    _actions[1] = Action::Attack;
    _actions[2] = Action::MoveForward;
    _actions[3] = Action::Attack;

    _owner = player;

}

Fantassin::~Fantassin() {
    _reach[1].clear();
    _reach.clear();

    // The _owner object has incomplete class type at this point..
    // delete _owner;
}
