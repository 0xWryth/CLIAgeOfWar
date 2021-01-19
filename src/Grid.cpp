#include "Grid.h"

Grid::Grid(const int gridSize, Game* game) {
    _gridSize = gridSize;
    _gridCases = std::vector<GridCase>(0);
    _game = game;

    // Game initialization
    Player p1 = _game->getPlayers().first;
    Player p2 = _game->getPlayers().second;

//    HomeCase* h = p1.getHomeCase();
//    std::cout << h << std::endl;

    HomeCase h1 = HomeCase(&p1, 0);
    HomeCase h2 = HomeCase(&p2, gridSize - 1);
    p1.setHomeCase(&h1);
    p2.setHomeCase(&h2);

    _gridCases.push_back(h1);
    for (int i = 1; i < gridSize - 1; ++i) {
        _gridCases.push_back(GridCase());
    }
    _gridCases.push_back(h2);
}

//void Grid::setGame(Game* game) {
//
//}

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

//        middleLine += _gridCases[i].isEmpty() ? "|   " : "| " + _gridCases[i].getTroupName(true) + " ";
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
