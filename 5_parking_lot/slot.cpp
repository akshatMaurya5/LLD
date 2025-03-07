// depends on vehicle.cpp

#include <iostream>
#include <string>
#include "vehicle.cpp"
using namespace std;

class Slot
{
public:
    int slotNo;
    string type;
    bool available;
    Vehicle *vehicle;

    Slot(int slotNo, string type)
    {
        this->slotNo = slotNo;
        this->type = type;
        this->available = true;
        this->vehicle = nullptr;
    }

    int getSlotNo()
    {
        return slotNo;
    }

    string getType()
    {
        return type;
    }

    bool isAvailable()
    {
        return available;
    }

    void park(Vehicle v)
    {
        vehicle = new Vehicle(v);
        available = false;
    }

    void unpark()
    {
        if (vehicle != nullptr)
        {
            delete vehicle;
            vehicle = nullptr;
        }
        available = true;
    }
};
