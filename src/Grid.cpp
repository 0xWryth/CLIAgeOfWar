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

void Grid::display() {
    Player p1 = _game->getPlayers().first;
    Player p2 = _game->getPlayers().second;

    std::string res = "  " + p1.getFirstLetter() + "  ";
    res += std::string(4 * (_gridSize - 2) - 1, ' ');
    res += "  " + p2.getFirstLetter();

    _game->getConsole().addToPanel(res, Panel::Left);

    std::string topLine = "";
    std::string middleLine = "";
    std::string bottomLine = "";
    for (int i = 0; i < _gridSize; ++i) {
        topLine += "+---";
        middleLine += "|   ";
        std::string numberToString = std::to_string(i);
        bottomLine += "  " + numberToString + std::string(numberToString.length() == 1 ? 1 : 0,' ' );
    }
    topLine += "+";
    middleLine += "|";

    _game->getConsole().addToPanel(topLine, Panel::Left);
    _game->getConsole().addToPanel(middleLine, Panel::Left);
    _game->getConsole().addToPanel(topLine, Panel::Left);
    _game->getConsole().addToPanel(bottomLine, Panel::Left);



}
