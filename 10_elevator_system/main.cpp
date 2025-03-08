#include "ElevatorSystem.h"
#include <iostream>

int main()
{
    ElevatorSystem system(3, 5);
    system.start();

    system.requestElevator(0, 5);
    system.requestElevator(3, 7);
    system.requestElevator(2, 8);

    for (long long i = 0; i < 1e8; i++)
    {
    };
    return 0;
}
