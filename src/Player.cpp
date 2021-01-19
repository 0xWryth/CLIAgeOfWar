#include "Player.h"


// Placed here to avoid forward issue, good idea ?
#include "HomeCase.h"


int Player::_playerNumber = 1;

Player::Player() {
    _playerName = "Player " + std::to_string(_playerNumber);
    _playerId = _playerNumber++ - 1;
    _coins = 0;
}

std::string Player::displayStr() {
    return "  " + _playerName + ": " + std::to_string(_coins) + " coins";
}

void Player::initialize(const Console console) {
    _playerName = console.prompt("Insert " + _playerName + " name :");
}

void Player::setHomeCase(HomeCase* homeCase) {
    _homeCase = homeCase;
}

std::string Player::getFirstLetter() {
    return std::string(1, _playerName[0]);
}

bool Player::isKO() {
    return _homeCase->getCurrentHealth() <= 0;
}

bool Player::canPlaceTroup() {
    return _homeCase->isEmpty();
}

void Player::placeTroupOnHomeCase(Troup *troup) {
    _homeCase->placeUnit(troup);
}

GridCase* Player::getHomeCase() {
    return _homeCase;
}
