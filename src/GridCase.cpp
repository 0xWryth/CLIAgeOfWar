#include "GridCase.h"

GridCase::GridCase(int position) {
    _position = position;
}

bool GridCase::placeUnit(Troup* unit) {
    if(_unit != nullptr)    // a unit is already placed here
        return false;

    _unit = unit;
    return true;
}