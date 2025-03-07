#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class Game
{
private:
    Board board;
    Player player1;
    Player player2;
    Player *currentPlayer;

public:
    Game();
    void switchTurn();
    void play();
};

#endif