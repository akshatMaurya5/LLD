#include "board.h"

Board::Board(int size) : size(size) {}

void Board::addSnake(int start, int end)
{
    snakes[start] = end;
}

void Board::addLadder(int start, int end)
{
    ladders[start] = end;
}

int Board::getNewPosition(int position)
{
    if (snakes.count(position))
        return snakes[position];
    if (ladders.count(position))
        return ladders[position];
    return position;
}
