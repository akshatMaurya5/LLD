#include "Elevator.h"
#include <iostream>
using namespace std;

Elevator::Elevator(int id, int capacity) : id(id), capacity(capacity), currentFloor(0), direction(0), isMoving(false) {}

void Elevator::addRequest(int floor)
{
    requests.push(floor);
    if (direction == 0)
    {
        direction = (floor > currentFloor) ? 1 : -1;
    }
}

void Elevator::move()
{
    if (isMoving)
        return;

    isMoving = true;

    while (!requests.empty())
    {
        auto nextFloor = requests.front();
        requests.pop();

        while (currentFloor != nextFloor)
        {

            cout << "Simulating the sleep here\n";
            for (long long i = 0; i < 1e8; i++)
                ;

            currentFloor += (nextFloor > currentFloor) ? 1 : -1;

            cout << "Elevator " << id << " is at floor " << currentFloor << endl;
        }

        std::cout << "Elevator " << id << " arrived at floor " << currentFloor << std::endl;

        cout << "Simulating the sleep here\n";
        for (long long i = 0; i < 1e8; i++)
            ;

        if (requests.empty())
            direction = 0;
    }
    isMoving = false;
}

int Elevator::getCurrentFloor()
{
    return currentFloor;
}

int Elevator::getDirection()
{
    return direction;
}

int Elevator::getId()
{
    return id;
}

bool Elevator::isIdle()
{
    return !isMoving && requests.empty();
}
