#ifndef REQUEST_H
#define REQUEST_H

class Request
{
public:
    int pickupFloor, destinationFloor;

    Request(int pickupFloor, int destinationFloor) : pickupFloor(pickupFloor), destinationFloor(destinationFloor) {}
};

#endif
