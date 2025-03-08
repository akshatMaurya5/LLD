#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <queue>
#include <mutex>
using namespace std;

class Elevator
{
private:
    int id;
    int currentFloor;
    int direction;
    int capacity;
    queue<int> requests;
    bool isMoving;

public:
    Elevator(int id, int capacity);

    void addRequest(int floor);
    void move();
    bool isIdle();
    int getCurrentFloor();
    int getDirection();
    int getId();
};

#endif
