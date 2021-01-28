#include "Grid.h"
#include <algorithm>

Grid::Grid(const int gridSize, Player& p1, Player& p2) {
    _gridSize = gridSize;
    _gridCases = std::vector<GridCase*>(0);

    _gridCases.push_back(&p1.getHomeCase());
    for (int i = 1; i < gridSize - 1; ++i) {
        _gridCases.push_back(new GridCase(i));
    }
    _gridCases.push_back(&p2.getHomeCase());
}

void Grid::display(Console& console, Player& p1, Player& p2) {
    std::string res = "  " + p1.getFirstLetter() + "  ";
    res += std::string(4 * (_gridSize - 2) - 1, ' ');
    res += "  " + p2.getFirstLetter();

    console.addToPanel(res, Panel::Left);

    std::string topLine = "";
    std::string middleLine = "";
    std::string lifeLine = "";
    std::string bottomLine = "";
    for (int i = 0; i < _gridSize; ++i) {
        topLine += "+---";

        bool isEmpty = _gridCases[i]->isEmpty();
        if (isEmpty) {
            middleLine += "|   ";
        }
        else {
            std::string name = _gridCases[i]->getTroupName(true);
            if (_gridCases[i]->getUnitOwner() == &p2) {
                std::for_each(name.begin(), name.end(), [](char & c) {
                    c = ::tolower(c);
                });
            }

            middleLine += "| " + name + " ";
        }

        int life = isEmpty ? 0 : _gridCases[i]->getUnit()->getCurrentHealth();
        std::string lifeInfo = life >= 10 ? std::to_string(life) : (std::to_string(life) + " ");

        lifeLine += _gridCases[i]->isEmpty() ? "|   " : "| " + lifeInfo;
        std::string numberToString = std::to_string(i);
        bottomLine += "  " + numberToString + std::string(numberToString.length() == 1 ? 1 : 0,' ' );
    }
    topLine += "+";
    middleLine += "|";
    lifeLine += "|";

    console.addToPanel(topLine, Panel::Left);
    console.addToPanel(middleLine, Panel::Left);
    console.addToPanel(lifeLine, Panel::Left);
    console.addToPanel(topLine, Panel::Left);
    console.addToPanel(bottomLine, Panel::Left);
}

void Grid::debug() {
    for (int i = 0; i < _gridSize; ++i) {
        std::cout << _gridCases[i]->isEmpty() << std::endl;
    }
}

GridCase *Grid::find(int position) {
    GridCase* res = NULL;
    for (int i = 0; i < _gridSize; i++) {
        if (_gridCases[i]->getPosition() == position) {
            res = _gridCases[i];
        }
    }

    return res;
}
