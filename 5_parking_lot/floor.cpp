// depends on slot.cpp

#include <iostream>
#include <vector>
#include "slot.cpp"
using namespace std;

class Floor
{
private:
    int floorNo;
    vector<Slot> slots;

public:
    Floor(int floorNo, int numSlots)
    {
        this->floorNo = floorNo;
        slots.push_back(Slot(1, "Truck"));
        slots.push_back(Slot(2, "Bike"));
        slots.push_back(Slot(3, "Bike"));
        for (int i = 4; i <= numSlots; i++)
        {
            slots.push_back(Slot(i, "Car"));
        }
    }

    int getFloorNo()
    {
        return floorNo;
    }

    int getFirstAvailableSlot(string vehicleType)
    {
        for (auto slot : slots)
        {
            if (slot.isAvailable() && slot.getType() == vehicleType)
            {
                return slot.getSlotNo();
            }
        }
        return -1;
    }

    void parkVehicle(int slotNo, Vehicle v)
    {
        slots[slotNo - 1].park(v);
    }

    void unparkVehicle(int slotNo)
    {
        slots[slotNo - 1].unpark();
    }

    int getFreeSlotCount(string vehicleType)
    {
        int count = 0;
        for (Slot &slot : slots)
        {
            if (slot.isAvailable() && slot.getType() == vehicleType)
            {
                count++;
            }
        }
        return count;
    }

    void displayFreeSlots(string vehicleType)
    {
        cout << "Free slots on Floor " << floorNo << " for " << vehicleType << ": ";
        for (Slot &slot : slots)
        {
            if (slot.isAvailable() && slot.getType() == vehicleType)
            {
                cout << slot.getSlotNo() << " ";
            }
        }
        cout << endl;
    }

    void displayOccupiedSlots(string vehicleType)
    {
        cout << "Occupied slots on Floor " << floorNo << " for " << vehicleType << ": ";
        for (Slot &slot : slots)
        {
            if (!slot.isAvailable() && slot.getType() == vehicleType)
            {
                cout << slot.getSlotNo() << " ";
            }
        }
        cout << endl;
    }
};
