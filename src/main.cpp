#include <iostream>
#include "Console.h"
#include "Player.h"
#include "Archer.h"

int main() {
    Console console = Console();
    console.addToPanel("Hello World", Panel::Top);

    console.addToPanel("Hey my name is Lucas", Panel::Left);
    console.addToPanel("I'm 19", Panel::Left);
    console.addToPanel("Currently studying at Polytech Paris-Saclay", Panel::Left);

    console.addToPanel("GP: 1", Panel::Right);
    console.addToPanel("Hmm.........", Panel::Right);

    console.display();

    console.clear();

    Player p = Player();
    p.display();

    return 0;
}