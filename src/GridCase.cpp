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
    std::cout << (!_filled ? "empty" : "not-empty") << &*this << _position << std::endl;

//    std::cout << (!_filled ? "empty" + std::to_string(_position) : "not empty" + std::to_string(_position)) << std::endl;
    return !_filled;
}

std::string GridCase::getTroupName(bool isShort) {
    return _unit->getName(isShort);
}
