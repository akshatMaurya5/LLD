#include "player.h"
#include <iostream>
using namespace std;
#include "board.cpp"

Player::Player(string n, char s) : name(n), symbol(s) {}

void Player::makeMove(Board &board)
{
    int row, col;

    while (true)
    {
        cout << name << " (" << symbol << "), enter row and column (0-2): ";
        cin >> row >> col;

        if (board.makeMove(row, col, symbol))
            break;
        cout << "Invalid move! Try again.\n";
    }
}