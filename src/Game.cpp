#include "Game.h"

Game::Game(const int gridSize, const int maxTurnLimit) {
    _maxTurnLimit = maxTurnLimit;
    _console = Console();
    _grid = new Grid(gridSize);
}

void Game::turn() {
    _console.display();
}
