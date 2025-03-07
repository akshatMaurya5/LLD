#include "game.h"
#include <iostream>
#include "board.cpp"
#include "player.cpp"
using namespace std;

Game::Game() : player1("Player 1", 'X'), player2("Player 2", 'O'), currentPlayer(&player1) {}

void Game::switchTurn()
{
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}

void Game::play()
{
    while (true)
    {
        board.display();
        currentPlayer->makeMove(board);

        if (board.checkWin(currentPlayer->symbol))
        {
            board.display();
            cout << currentPlayer->name << " wins!\n";
            break;
        }

        if (board.isFull())
        {
            board.display();
            cout << "It's a draw!\n";
            break;
        }

        switchTurn();
    }
}
