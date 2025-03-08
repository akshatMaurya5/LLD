#include "ElevatorSystem.h"
#include <iostream>
#include <climits>
#include <thread>
#include <limits>

ElevatorSystem::ElevatorSystem(int numElevators, int capacity)
{
    for (int i = 0; i < numElevators; i++)
    {
        elevators.emplace_back(i + 1, capacity);
    }
}
void ElevatorSystem::requestElevator(int pickupFloor, int destinationFloor)
{
    int bestElevatorId = -1;
    int minDistance = INT_MAX;

    for (auto &elevator : elevators)
    {
        int distance = abs(elevator.getCurrentFloor() - pickupFloor);
        if (distance < minDistance && ((elevator.getDirection() == 1 && pickupFloor >= elevator.getCurrentFloor()) ||
                                       (elevator.getDirection() == -1 && pickupFloor <= elevator.getCurrentFloor())))
        {
            minDistance = distance;
            bestElevatorId = elevator.getId();
        }
    }

    if (bestElevatorId == -1)
    {
        bestElevatorId = 1; // Fallback
    }

    for (auto elevator : elevators)
    {
        if (elevator.getId() == bestElevatorId)
        {
            cout << "Elevator " << elevator.getId() << " assigned to pickup at floor " << pickupFloor << endl;
            elevator.addRequest(pickupFloor);
            elevator.addRequest(destinationFloor);
            return;
        }
    }
}

void ElevatorSystem::start()
{
    std::cout << "Elevator system started!" << std::endl;
}
