#include "Game.h"

Game::Game(const int gridSize, const int maxTurnLimit, const int earnings) {
    _maxTurnLimit = maxTurnLimit;
    _console = Console();
    _grid = new Grid(gridSize);
    _grid->setGame(this);
    _earnings = earnings;
    _currentTurn = 0;

    _consoleHeader = "> CLI Age of War\n- Lucas Briatte Vatel\n- Antonin Depreissat\n  Polytech Paris-Saclay - 2020-2021";
    initializeGame();
}

void Game::turn() {
    do {
        // each player earn some credits
        _players.first.incrementCoins(_earnings);
        _players.second.incrementCoins(_earnings);

        play(_players.first);
        play(_players.second);

        _currentTurn++;
    } while(_currentTurn < _maxTurnLimit);  // TODO : "&& noWinner"...
}

void Game::play(Player p) {
    _console.clear();
    _console.addToPanel(_consoleHeader, Panel::Top);
    displayPlayer();

    std::string whosTurn = "\nTour n°" + std::to_string(_currentTurn)
        + ". C'est au tour du joueur "
        + p.getName() + ".\n";
    _console.addToPanel(whosTurn, Panel::Bottom);

    _console.display();

    std::string playerAction = _console.prompt("Action à jouer :");

    do {
        playerAction = _console.prompt("Action à jouer :");
        // TODO: handle player input (game "actions" to define)
    } while(playerAction.size() != 1);
}

void Game::initializeGame() {
    _console.addToPanel(_consoleHeader, Panel::Top);
    _console.display();

    _players.first.initialize(_console);
    _players.second.initialize(_console);

    _currentTurn++;
    turn();
}

void Game::displayPlayer() {
    _console.addToPanel("Bank:", Panel::Right);
    _console.addToPanel(_players.first.displayStr(), Panel::Right);
    _console.addToPanel(_players.second.displayStr(), Panel::Right);
    _console.addToPanel("", Panel::Right);
    _console.addToPanel("Help:", Panel::Right);
    _console.addToPanel("  [F]antassin", Panel::Right);
    _console.addToPanel("  [A]rcher", Panel::Right);
    _console.addToPanel("  [C]atapult", Panel::Right);
    _console.addToPanel("  [S]uper-soldier", Panel::Right);
}

const std::pair<Player, Player> &Game::getPlayers() const {
    return _players;
}

Console &Game::getConsole() {
    return _console;
}
