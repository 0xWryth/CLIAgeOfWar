#ifndef CLIAGEOFWAR_CONSOLE_H
#define CLIAGEOFWAR_CONSOLE_H

#include <iostream>
#include <vector>
#include <map>
#include "Panel.h"

class Console {
    std::map<Panel,std::vector<std::string>> _panels;
    int getMaxChar() const;
public:
    Console();
    void addToPanel(const std::string toAppend, Panel position);
    void display() const;
    void clear();
    std::string prompt(std::string message) const;
};


#endif //CLIAGEOFWAR_CONSOLE_H