#include "dice.h"

int Dice::roll()
{
    return rand() % 6 + 1;
}