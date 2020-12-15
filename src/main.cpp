#include <iostream>
#include "Console.h"

int main() {
    std::cout << "Hello World!" << std::endl;

    Console console = Console();
    console.addToLeftPanel("Hey my name is Lucas");
    console.addToLeftPanel("I'm 19");
    console.addToLeftPanel("Currently studying at Polytech Paris-Saclay");

    console.addToRightPanel("GP: 1");
    console.addToRightPanel("Hmm.........");

    console.display();

    return 0;
}