#include "Player.h"

int Player::_playerNumber = 1;

Player::Player() {
    _playerName = "Player " + std::to_string(_playerNumber);
    _playerId = _playerNumber++ - 1;
}

void Player::display() {
    std::cout << _playerName << ": " << _playerId << std::endl;
}
