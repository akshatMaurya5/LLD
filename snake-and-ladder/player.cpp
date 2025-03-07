#include "player.h"

Player::Player(string name) : name(name), position(1) {}

void Player::move(int steps)
{
    position += steps;
}

int Player::getPosition()
{
    return position;
}

string Player::getName()
{
    return name;
}