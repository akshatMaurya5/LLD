#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"
#include "dice.h"
#include <vector>
#include <string>

class Game
{
private:
    Board board;
    vector<Player> players;
    Dice dice;
    int currentPlayerIndex;

public:
    Game(int baardSize);
    void addPlayer(string name);
    void play();
};

#endif
