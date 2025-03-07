#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "board.h"

class Player
{
public:
    string name;
    char symbol;

    Player(string n, char s);
    void makeMove(Board &board);
};

#endif