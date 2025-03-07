#include <iostream>
#include <vector>
#include "board.h"
using namespace std;

Board::Board(int n) : size(n), grid(n, vector<char>(n, ' ')) {}

void Board::display()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << grid[i][j];
            if (j < size - 1)
                cout << " | ";
        }
        cout << "\n";
        if (i < size - 1)
            cout << "---------\n";
    }
}

bool Board::makeMove(int row, int col, char symbol)
{
    if (row >= 0 && row < size && col >= 0 && col < size && grid[row][col] == ' ')
    {
        grid[row][col] = symbol;
        return true;
    }
    return false;
}

bool Board::checkWin(char symbol)
{
    for (int i = 0; i < size; i++)
    {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol)
            return true;
        if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)
            return true;
    }
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
        return true;
    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)
        return true;

    return false;
}

bool Board::isFull()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (grid[i][j] == ' ')
                return false;
        }
    }
    return true;
}