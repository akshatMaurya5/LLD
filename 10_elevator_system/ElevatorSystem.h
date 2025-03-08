#ifndef ELEVATORSYSTEM_H
#define ELEVATORSYSTEM_H

#include "Elevator.h"
#include "Request.h"
#include <vector>

using namespace std;

class ElevatorSystem
{
private:
    vector<Elevator> elevators;

public:
    ElevatorSystem(int numElevators, int capacity);
    void requestElevator(int pickupFloor, int destinationFloor);
    void start();
};

#endif
