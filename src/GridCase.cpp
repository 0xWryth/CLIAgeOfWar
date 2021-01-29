#include <iostream>
#include "GridCase.h"

GridCase::GridCase(int position) {
    _position = position;
    _filled = false;
    _unit = NULL;
}

bool GridCase::placeUnit(Troup* unit) {
    if (_filled) { // a unit is already there
        return false; // unit can't be placed
    }
    else {
        _filled = true; // update unit
        _unit = unit;
        return true;  // unit has been placed
    }
}

bool GridCase::isEmpty() {
    return !_filled;
}

std::string GridCase::getTroupName(bool isShort) {
    return _unit->getName(isShort);
}

Troup *GridCase::getUnit() const {
    return _unit;
}

int GridCase::getPosition() const {
    return _position;
}

void GridCase::transferTroupToCase(GridCase* gridCase) {
    gridCase->placeUnit(this->getUnit());
    this->_filled = false;
}

bool GridCase::suffersAttack(int damage) {
    if (_filled) {
        _unit->removeHealth(damage);

        if (_unit->getCurrentHealth() <= 0) {
            _unit = NULL;
            _filled = false; // free case
            return true;  // unit is dead
        }

        return false;  // unit is not dead
    } else {
        std::cout << "attaque sur une case vide !" << std::endl;
        return false; // should not be reached but..
    }
}