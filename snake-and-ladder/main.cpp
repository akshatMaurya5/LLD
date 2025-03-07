#include "Game.h"

int main()
{
    Game game(30);
    game.addPlayer("Alice");
    game.addPlayer("Bob");
    game.play();
    return 0;
}

// compilation command

// g++ main.cpp Game.cpp Board.cpp Player.cpp Dice.cpp -o snake_ladder

// just testing out
