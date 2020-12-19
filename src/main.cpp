#include <iostream>
#include "Console.h"
#include "Player.h"
#include "Archer.h"

int main() {
    std::cout << "Hello World!" << std::endl;

    Console console = Console();
    console.addToLeftPanel("Hey my name is Lucas");
    console.addToLeftPanel("I'm 19");
    console.addToLeftPanel("Currently studying at Polytech Paris-Saclay");

    console.addToRightPanel("GP: 1");
    console.addToRightPanel("Hmm.........");

    console.display();

    console.clear();

    Player p = Player();
    p.display();

    return 0;
}