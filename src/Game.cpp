#include "Game.h"
#include "Fantassin.h"
#include "Archer.h"
#include "Catapult.h"
#include <algorithm>
#include <vector>

#define PHASE_1     1
#define PHASE_2     2
#define PHASE_3     3

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

        resolveActions(_p1);
        // TODO: if player 1 wins, exit before P1 unit creation and P2 turn (?)
        play(_p1);

        resolveActions(_p2);
        play(_p2);

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
            // If homecase is not filled
            if (p->canPlaceTroup()) {
                Troup *newTroup = NULL;
                switch (std::toupper(playerAction.at(0))) { // or .front()
                    case 'F':
                        newTroup = new Fantassin(p);
                        //_grid->debug();
                        break;
                    case 'A':
                        newTroup = new Archer(p);
                        break;
                    case 'C':
                        newTroup = new Catapult(p);
                        break;
                    case 'P':   // pass new unit creation
                        playerAction = "P";
                        break;
                    default:
                        // deal with default :
                        playerAction = "";
                }
                if (newTroup != NULL) {
                    if (p->getCoins() > newTroup->getCost()) {
                        p->placeTroupOnHomeCase(newTroup);
                    }
                    else {
                        std::cout << "You do not have enough money for this action." << std::endl;
                        playerAction = "";
                    }
                }
            }
            else {
                playerAction = " ";
            }
        }
    } while(playerAction.size() != 1);

}

void Game::resolveActions(Player* p) {
    bool unableToDoAction1 = false;

    // The following action handling loop is made for the left player
    // so for the right player, we swap the grid (restored after the loop).
    if(p == _p2) std::reverse(_grid->getAllCases().begin(), _grid->getAllCases().end());

    for (int phase = PHASE_1; phase <= PHASE_3; phase++) {
        /* Problematic of "direction of iteration" :
            - from the nearest unit to the farthest one (phase 1)
            - from the farthest unit to the nearest one (phases 2 & 3)

            -> way to handle this : the grid is reversed (depending on who plays and which is
               the current phase) so that the iterator always goes from the left to the right.
         */
         if(phase == PHASE_1 || phase == PHASE_2) std::reverse(_grid->getAllCases().begin(), _grid->getAllCases().end());


        std::cout << "Resolution des actions " << phase << " du joueur " << p->getName()
                  << ", unableToDoAction1=" << unableToDoAction1 << std::endl;

        /* TODO : handle action limitations during 3rd phase :
            restrict to (unableToDoAction1 && (Fantassin || Catapult)) || SuperSoldier)

           TODO : handle unit range
         */

        for (std::vector<GridCase*>::iterator it = _grid->getAllCases().begin();
             it != _grid->getAllCases().end();
             it++)
        {
            if (!(*it)->isEmpty() && (*it)->getUnitOwner() == p) {
                switch((*it)->getUnitAction(phase)) {
                    case Action::Attack:
                        // handle Attack action : if(!(*it+range)->isEmpty()) ... elif(Fantassin || Catapult)) !unableToDoAction1
                        std::cout << "Unit "<< (*it)->getTroupName() << " attacks !" << std::endl;
                        break;
                    case Action::MoveForward:
                        // handle MoveForward action : if(canReach) ... elif(Fantassin || Catapult)) !unableToDoAction1
                        std::cout << "Unit "<< (*it)->getTroupName() << " moves forward !" << std::endl;
                        break;
                    case Action::None:
                        // handle None action
                        break;
                    default:
                        break;
                }
                // if(actionHandleReturnsFalse) unableToDoAction1 = true;
            }
        }
    }


    if(p == _p2) std::reverse(_grid->getAllCases().begin(), _grid->getAllCases().end());

    /* TODO : display all unit activities
        eg : "Player1's F goes forward,
              Player1's C attacks Player2's A,
              Player2's A loses x PV"
    */
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
