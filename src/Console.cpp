#include "Console.h"

int Console::getMaxChar() const {
    int leftSize = this->_panels.at(Panel::Left).size();
    int maxChar = 0;

    for (auto i = 0; i < leftSize; ++i) {
        auto s = this->_panels.at(Panel::Left)[i];
        int le = s.length();
        if (le > maxChar) {
            maxChar = le;
        }
    }

    return maxChar;
}

void Console::display() const {
    std::cout << "\033[2J\033[1;1H";

    auto topSize = this->_panels.at(Panel::Top).size();
    for (long unsigned int i = 0; i < topSize; ++i) {
        std::cout << this->_panels.at(Panel::Top)[i] << std::endl;
    }
    std::cout << std::endl;
    
    auto leftSize = this->_panels.at(Panel::Left).size();
    auto rightSize = this->_panels.at(Panel::Right).size();

    auto const maxChar = this->getMaxChar();

    auto const separatorDist = 10;

    auto max = leftSize > rightSize ? leftSize : rightSize;
    
    for (long unsigned int i = 0; i < max; ++i) {
        std::string left = "";
        std::string right = "";

        if (i < leftSize) {
            left += this->_panels.at(Panel::Left)[i];
            auto spaceNeeded = maxChar - left.length();
            left += std::string(spaceNeeded, ' ');
        }
        else {
            left += std::string(maxChar, ' ');
        }
        if (i < rightSize) {
            right += this->_panels.at(Panel::Right)[i];
        }
        
        std::cout << left << std::string(separatorDist, ' ') << right << std::endl;
    }

    auto bottomSize = this->_panels.at(Panel::Bottom).size();
    for (long unsigned int i = 0; i < bottomSize; ++i) {
        std::cout << this->_panels.at(Panel::Bottom)[i] << std::endl;
    }
}

Console::Console() {
    for (auto p : all_Panel) {
        _panels[p] = std::vector<std::string>(0);
    }
}

void Console::clear() {
    for (auto p : all_Panel) {
        _panels[p].clear();
    }
}

std::string Console::prompt(std::string message) const {
    std::cout << message << std::endl;

    std::string res;
    std::cin >> res;

    return res;
}

void Console::addToPanel(const std::string toAppend, Panel position) {
    this->_panels[position].push_back(toAppend);
}
