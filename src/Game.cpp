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

        std::string actions = resolveActions(_p1);
        // TODO: if player 1 wins, exit before P1 unit creation and P2 turn (?)
        play(_p1, actions);

        actions = resolveActions(_p2);
        play(_p2, actions);

        _currentTurn++;
    } while(_currentTurn <= _maxTurnLimit  // max turn exceeded or no winner
            && !_p1->isKO()
            && !_p2->isKO() );

    if(_currentTurn >= _maxTurnLimit)
        std::cout << "End of the game, the maximum number of turn is reached."; // Name a winner anyway?
    else if(_p1->isKO())
        std::cout << "End of the game, " << _p1->getName() << "'s base is KO !";
    else
        std::cout << "End of the game, " << _p2->getName() << "'s base is KO !";
}

void Game::play(Player* p, std::string actionStr) {
    _console.clear();
    _console.addToPanel(_consoleHeader, Panel::Top);
    displayPlayer();
    _grid->display(_console, *_p1, *_p2);

    std::string whosTurn = "\nTurn n°" + std::to_string(_currentTurn)
                           + ". It's " + p->getName() + "'s turn.\n";
    _console.addToPanel(whosTurn, Panel::Bottom);

    _console.display();
    
    std::cout << actionStr << std::endl;

    std::string playerAction = "";

    do {
        if (!p->canPlaceTroup()) {
            std::cout << "You can't recruit a troup now because your base is occupied." << std::endl;
            playerAction = _console.prompt("(Press 'Enter' to skip unit creation)", true);
            playerAction = "P";
        }
        else {
            // If homecase is not filled

            playerAction = _console.prompt("Unit to create (see \"Help\" section) :");
        }

        if (playerAction.size() == 1) {
            Troup *newTroup = NULL;
            switch (std::toupper(playerAction.at(0))) { // or .front()
                case 'F':
                    newTroup = new Fantassin(p);
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
    } while (playerAction.size() != 1);

}

std::string Game::resolveActions(Player* p) {
    std::string res = "";

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


        res += p->getName() + "'s actions resolution phase " + std::to_string(phase) + " unable=" + std::to_string(unableToDoAction1) + "\n";


        bool moved = false;

        for (std::vector<GridCase*>::iterator it = _grid->getAllCases().begin();
             it != _grid->getAllCases().end();
             it++)
        {
            /* TODO : handle action limitations during 3rd phase : restrict to
                if(unableToDoAction1 && (Fantassin || Catapult)) || SuperSoldier)
                    continue;
             */
            if (!moved && !(*it)->isEmpty() && (*it)->getUnitOwner() == p) {
                int casePosition = (*it)->getPosition();

                int moveDirection = p == _p1 ? 1 : -1;

                switch((*it)->getUnitAction(phase)) {
                    case Action::Attack: {
                        // perform Attack action
                        GridCase* target = (*it)->getUnit()->canAttack(_grid, casePosition, moveDirection);
                        if(target != nullptr) {
                           res += (*it)->getUnit()->attack(_grid, target);

                            // if(!_grid->find(casePosition + moveDirection)->isEmpty()) {

                        } else {
                            // if(PHASE_1 && Fantassin) unableToDoAction1 = true;
                            std::cout << "Personne a attaquer..." << std::endl;
                        }
                        break;
                    }
                    case Action::MoveForward: {
                        if ((p == _p1 && casePosition >= this->_grid->getGridSize() - 1 - 1) ||
                            (p == _p2 && casePosition <= 1) ||
                            !this->_grid->find(casePosition + moveDirection)->isEmpty()) {
                            res += "\tUnit " + (*it)->getTroupName() + " can not go forward !"
                                    + std::to_string(casePosition) +
                                    std::to_string(this->_grid->getGridSize() - 1)
                                    + "\n";
                        } else {
                            (*it)->transferTroupToCase(_grid->find(casePosition + moveDirection));
                            moved = true;

                            res += "\tUnit " + (*it)->getTroupName() + " moves forward !" + "\n";
                        }

                        break;
                    }
                    case Action::None: // no handling needed
                    default:
                        break;
                }
                // if(actionHandleReturnsFalse) unableToDoAction1 = true;
            }
            else if (moved) {
                moved = false;
            }
        }
    }


    if(p == _p2) std::reverse(_grid->getAllCases().begin(), _grid->getAllCases().end());

    /* TODO : display all unit activities
        eg : "Player1's F goes forward,
              Player1's C attacks Player2's A,
              Player2's A loses x PV"
    */

    return res;
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
