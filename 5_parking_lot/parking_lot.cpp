// manages multiple floors

#include <vector>
#include <iostream>
#include "floor.cpp"
using namespace std;

class ParkingLot
{
private:
    string parkingLotId;
    vector<Floor> floors;

public:
    ParkingLot(string parkingLotId, int numFloors, int numSlotsPerFloor)
    {
        this->parkingLotId = parkingLotId;
        for (int i = 0; i < numFloors; i++)
        {
            floors.push_back(Floor(i + 1, numSlotsPerFloor));
        }
        cout << "Created parking lot with " << numFloors << " floors and " << numSlotsPerFloor << " slots per floor" << endl;
    }

    string parkVehicle(string vehicleType, string regNo, string color)
    {
        for (auto floor : floors)
        {
            int slotNo = floor.getFirstAvailableSlot(vehicleType);
            if (slotNo != -1)
            {
                string ticketId = parkingLotId + "-" + to_string(floor.getFloorNo()) + "-" + to_string(slotNo);
                floor.parkVehicle(slotNo, Vehicle(vehicleType, regNo, color));
                cout << "Parked vehicle. Ticket ID: " << ticketId << endl;
                return ticketId;
            }
        }
        return "Parking lot is full";
    }

    void unparkVehicle(string ticketId)
    {
        int floorNo, slotNo;
        sscanf(ticketId.c_str(), "PR1234_%d_%d", &floorNo, &slotNo);
        if (floorNo > 0 && floorNo <= floors.size())
        {
            floors[floorNo - 1].unparkVehicle(slotNo);
            cout << "Unparked vehicle with Ticket ID: " << ticketId << endl;
        }
        else
        {
            cout << "Invalid Ticket ID" << endl;
        }
    }

    void display(string type, string vehicleType)
    {
        if (type == "free_count")
        {
            for (Floor &floor : floors)
            {
                cout << "Floor " << floor.getFloorNo() << " has " << floor.getFreeSlotCount(vehicleType) << " free slots" << endl;
            }
        }
        else if (type == "free_slots")
        {
            for (Floor &floor : floors)
            {
                floor.displayFreeSlots(vehicleType);
            }
        }
        else if (type == "occupied_slots")
        {
            for (Floor &floor : floors)
            {
                floor.displayOccupiedSlots(vehicleType);
            }
        }
    }
};
