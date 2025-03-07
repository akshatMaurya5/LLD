#include "game.h"
#include <iostream>

using namespace std;

Game::Game(int boardSize) : board(boardSize), currentPlayerIndex(0)
{
    board.addSnake(17, 7);
    board.addLadder(3, 22);
}

void Game::addPlayer(string name)
{
    players.push_back(Player(name));
}

void Game::play()
{

    while (true)
    {
        Player &player = players[currentPlayerIndex];

        int roll = dice.roll();
        cout << player.getName() << " rolled a " << roll << endl;

        player.move(roll);

        int newPos = board.getNewPosition(player.getPosition()); // final pos based on snake or ladder

        player.move(newPos - player.getPosition());

        cout << player.getName() << " is at position " << player.getPosition() << endl;

        // check if player has won
        if (player.getPosition() > 30)
        {
            cout << player.getName() << " has won" << endl;
            break;
        }

        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }
};
