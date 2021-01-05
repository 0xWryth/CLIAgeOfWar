#include "Player.h"

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

void Player::setHomeCase(HomeCase *homeCase) {
    _homeCase = homeCase;
}

char Player::getFirstLetter() {
    return _playerName[0];
}
