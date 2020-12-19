#include "Console.h"

int Console::getMaxChar() {
    int leftSize = this->_leftPanel.size();
    int maxChar = 0;

    for (auto i = 0; i < leftSize; ++i) {
        auto s = this->_leftPanel[i];
        int le = s.length();
        if (le > maxChar) {
            maxChar = le;
        }
    }

    return maxChar;
}

void Console::display() {
    auto leftSize = this->_leftPanel.size();
    auto rightSize = this->_rightPanel.size();

    auto const maxChar = this->getMaxChar();

    auto const separatorDist = 10;

    auto max = leftSize > rightSize ? leftSize : rightSize;
    for (long unsigned int i = 0; i < max; ++i) {
        std::string left = "";
        std::string right = "";

        if (i < leftSize) {
            left += _leftPanel[i];
            auto spaceNeeded = maxChar - left.length();
            left += std::string(spaceNeeded, ' ');
        }
        else {
            left += std::string(maxChar, ' ');
        }
        if (i < rightSize) {
            right += _rightPanel[i];
        }
        
        std::cout << left << std::string(separatorDist, ' ') << right << std::endl;
    }
}

void Console::addToLeftPanel(const std::string toAppend) {
    this->_leftPanel.push_back(toAppend);
}

void Console::addToRightPanel(const std::string toAppend) {
    this->_rightPanel.push_back(toAppend);
}

Console::Console() {
    this->_leftPanel = std::vector<std::string>(0);
    this->_rightPanel = std::vector<std::string>(0);
}

void Console::clear() {
    this->_leftPanel.clear();
    this->_rightPanel.clear();
}

std::string Console::prompt(std::string message) {
    std::cout << message << std::endl;

    std::string res;
    std::cin >> res;

    return res;
}
