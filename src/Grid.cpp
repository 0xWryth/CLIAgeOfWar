#include "Grid.h"

Grid::Grid(const int gridSize) {
    _gridSize = gridSize;
    _gridCases = new GridCase[_gridSize];
}

void Grid::setGame(Game* game) {
    _game = game;

    // Game initialization
    Player p1 = _game->getPlayers().first;
    Player p2 = _game->getPlayers().second;

    // Initializing case value
    for (int i = 0; i < _gridSize; ++i) {
        _gridCases[i] = i == 0 ? HomeCase(&p1, i) : i == 1 ? HomeCase(&p2, i) : GridCase(i);
    }
}

std::string Grid::displayStr() {
    Player p1 = _game->getPlayers().first;
    Player p2 = _game->getPlayers().second;

    std::string res = "  " + std::to_string(p1.getFirstLetter()) + "  ";
    res += std::string(" ", 4 * (_gridSize - 2) - 1);
    res += "  " + std::to_string(p2.getFirstLetter()) + "  ";

    _game->getConsole().addToPanel(res, Panel::Left);

    return "";
}
