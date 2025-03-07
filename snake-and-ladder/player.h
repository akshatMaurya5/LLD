#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
private:
    string name;
    int position;

public:
    Player(string name);

    void move(int steps);
    int getPosition();
    string getName();
};

#endif
