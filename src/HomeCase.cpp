#include "HomeCase.h"

HomeCase::HomeCase(Player *owner, int position) : GridCase(position) {
    _owner = owner;

    // inherited attributes are hardcoded here (temporarily ? later from xml/txt file ?)
    _initialHealth = 100;
    _currentHealth = 100;
}
