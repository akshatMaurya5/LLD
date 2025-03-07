#ifndef BOARD_H
#define BOARD_H

#include <unordered_map>
using namespace std;

class Board
{
private:
    int size;
    unordered_map<int, int> snakes;
    unordered_map<int, int> ladders;

public:
    Board(int size);
    void addSnake(int start, int end);
    void addLadder(int start, int end);
    int getNewPosition(int position);
};

#endif
