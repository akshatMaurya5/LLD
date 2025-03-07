#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
using namespace std;

class Board
{
private:
    vector<vector<char>> grid;
    int size;

public:
    Board(int n = 3);
    void display();
    bool makeMove(int row, int col, char symbol);
    bool checkWin(char symbol);
    bool isFull();
};

#endif