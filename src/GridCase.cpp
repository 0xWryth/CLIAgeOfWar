#include "GridCase.h"

GridCase::GridCase(int position) {
    _position = position;
    _filled = false;
    _unit = NULL;
}

bool GridCase::placeUnit(Troup* unit) {
    if (_filled) {
        return false;
    }

    _filled = true;
    _unit = unit;
    return true;
}

bool GridCase::isEmpty() {
    return _filled;
}

std::string GridCase::getTroupName(bool isShort) {
    return _unit->getName(isShort);
}
