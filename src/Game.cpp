#include "Game.h"
#include "Fantassin.h"
#include "Archer.h"
#include "Catapult.h"

Game::Game(const int gridSize, const int maxTurnLimit, const int earnings) {
    _maxTurnLimit = maxTurnLimit;
    _console = Console();
    _earnings = earnings;
    _currentTurn = 0;

    HomeCase h1 = HomeCase(0);
    _p1 = new Player(h1);

    HomeCase h2 = HomeCase(gridSize - 1);
    _p2 = new Player(h2);

    _consoleHeader = "> CLI Age of War\n- Lucas Briatte Vatel\n- Antonin Depreissat\n  Polytech Paris-Saclay - 2020-2021";
    initializeGame(gridSize);
}

void Game::turn() {
    do {
        // each player earn some credits
        _p1->incrementCoins(_earnings);
        _p2->incrementCoins(_earnings);

        play(_p1);
        play(_p1);  // todo: if player 1 wins, exit before P2 turn (?)

        _currentTurn++;
//    } while(_currentTurn <= _maxTurnLimit  // max turn exceeded or no winner
//            && !_players.first.isKO()
//            && !_players.second.isKO() );
    } while(true);

    if(_currentTurn >= _maxTurnLimit)
        std::cout << "End of the game, the maximum number of turn is reached.";
    else if(_p1->isKO())
        std::cout << "End of the game, " << _p1->getName() << "'s base is KO !";
    else
        std::cout << "End of the game, " << _p2->getName() << "'s base is KO !";
}

void Game::play(Player* p) {
    _console.clear();
    _console.addToPanel(_consoleHeader, Panel::Top);
    displayPlayer();
    _grid->display(_console, *_p1, *_p2);

    std::string whosTurn = "\nTurn n°" + std::to_string(_currentTurn)
                           + ". It's " + p->getName() + "'s turn.\n";
    _console.addToPanel(whosTurn, Panel::Bottom);

    _console.display();

    std::string playerAction = "";

    do {
        playerAction = _console.prompt("Unit to create (see \"Help\" section) :");

        if(playerAction.size() == 1) {

            /* TODO:
                - handle player input (unit "actions" to define : 'F', 'C', ...)
                - before purchase, check if player have enough coins
                - then, remove corresponding cost
            */

            if (p->canPlaceTroup()) {
                switch (std::toupper(playerAction.at(0))) { // or .front()
                    case 'F':
                        p->placeTroupOnHomeCase(new Fantassin());
                        //_grid->debug();
                        break;
                    case 'A':
                        p->placeTroupOnHomeCase(new Archer());
                        break;
                    case 'C':
                        p->placeTroupOnHomeCase(new Catapult());
                        break;
                    case 'P':   // pass new unit creation
                        break;
                    default:
                        // deal with default :
                        playerAction = "";
                }
            }
            else {
                playerAction = "";
            }
        }
    } while(playerAction.size() != 1);

}

void Game::initializeGame(int gridSize) {
    _console.addToPanel(_consoleHeader, Panel::Top);
    _console.display();

    _p1->initialize(_console);
    _p2->initialize(_console);

    _grid = new Grid(gridSize, *_p1, *_p2);

    _currentTurn++;
    turn();
}

void Game::displayPlayer() {
    _console.addToPanel("Bank:", Panel::Right);
    _console.addToPanel(_p1->displayStr(), Panel::Right);
    _console.addToPanel(_p2->displayStr(), Panel::Right);
    _console.addToPanel("", Panel::Right);
    _console.addToPanel("Help:", Panel::Right);
    _console.addToPanel("  [F]antassin", Panel::Right);
    _console.addToPanel("  [A]rcher", Panel::Right);
    _console.addToPanel("  [C]atapult", Panel::Right);
    _console.addToPanel("  [P]ass unit recruitment", Panel::Right);
}

Console &Game::getConsole() {
    return _console;
}
