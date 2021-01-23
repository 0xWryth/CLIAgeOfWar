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
