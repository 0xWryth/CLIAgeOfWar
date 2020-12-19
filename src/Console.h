#ifndef CLIAGEOFWAR_CONSOLE_H
#define CLIAGEOFWAR_CONSOLE_H

#include <iostream>
#include <vector>

class Console {
    std::vector<std::string> _leftPanel;
    std::vector<std::string> _rightPanel;
    int getMaxChar();
public:
    Console();
    void addToLeftPanel(const std::string toAppend);
    void addToRightPanel(const std::string toAppend);
    void display();
    void clear();
    std::string prompt(std::string message);
};


#endif //CLIAGEOFWAR_CONSOLE_H