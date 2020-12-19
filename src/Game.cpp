#include "Game.h"

Game::Game(const int gridSize, const int maxTurnLimit, const int earnings) {
    _maxTurnLimit = maxTurnLimit;
    _console = Console();
    _grid = new Grid(gridSize);
    _earnings = earnings;

    _consoleHeader = "> CLI Age of War\n- Lucas Briatte Vatel\n- Antonin Depreissat\n  Polytech Paris-Saclay - 2020-2021";
    initializeGame();
}

void Game::turn() {
    _console.clear();
    _console.addToPanel(_consoleHeader, Panel::Top);
    displayPlayer();
    _console.display();
}

void Game::initializeGame() {
    _console.addToPanel(_consoleHeader, Panel::Top);
    _console.display();

    _players.first.initialize(_console);
    _players.second.initialize(_console);

    turn();
}

void Game::displayPlayer() {
    _console.addToPanel("Bank:", Panel::Right);
    _console.addToPanel(_players.first.displayStr(), Panel::Right);
    _console.addToPanel(_players.second.displayStr(), Panel::Right);
}
