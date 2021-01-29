#include "Player.h"
#include <algorithm>

// Placed here to avoid forward issue, good idea ?
#include "HomeCase.h"


int Player::_playerNumber = 1;

Player::Player(HomeCase &homeCase) : _homeCase(homeCase) {
    _playerName = "Player " + std::to_string(_playerNumber);
    _playerId = _playerNumber++ - 1;
    _coins = 0;
}

std::string Player::displayStr() {
    std::string name = _playerName;
    if (_playerId == 0) {
        std::for_each(name.begin(), name.end(), [](char & c) {
            c = ::toupper(c);
        });
    }
    else {
        std::for_each(name.begin(), name.end(), [](char & c) {
            c = ::tolower(c);
        });
    }
    return "  " + name + ": " + std::to_string(_coins) + " coins";
}

void Player::initialize(const Console console) {
    _playerName = console.prompt("Insert " + _playerName + " name :");
}

std::string Player::getFirstLetter() {
    return std::string(1, _playerName[0]);
}

bool Player::isKO() {
    return _homeCase.getCurrentHealth() <= 0;
}

bool Player::canPlaceTroup() {
    return _homeCase.isEmpty();
}

bool Player::placeTroupOnHomeCase(Troup *troup) {
    _coins -= troup->getCost();
    return _homeCase.placeUnit(troup);
}

HomeCase& Player::getHomeCase() {
    return _homeCase;
}

int Player::getCoins() const {
    return _coins;
}
