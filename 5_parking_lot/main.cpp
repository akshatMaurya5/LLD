#include <iostream>
#include <sstream>
#include "parking_lot.cpp"

using namespace std;

int main()
{
    ParkingLot *parkingLot = nullptr;
    string command;

    while (true)
    {
        getline(cin, command);
        if (command == "exit")
        {
            break;
        }

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "create_parking_lot")
        {
            string id;
            int floors, slots;
            ss >> id >> floors >> slots;
            parkingLot = new ParkingLot(id, floors, slots);
        }
        else if (action == "park_vehicle")
        {
            string type, regNo, color;
            ss >> type >> regNo >> color;
            if (parkingLot)
            {
                parkingLot->parkVehicle(type, regNo, color);
            }
            else
            {
                cout << "Parking lot not created yet!" << endl;
            }
        }
        else if (action == "unpark_vehicle")
        {
            string ticketId;
            ss >> ticketId;
            if (parkingLot)
            {
                parkingLot->unparkVehicle(ticketId);
            }
            else
            {
                cout << "Parking lot not created yet!" << endl;
            }
        }
        else if (action == "display")
        {
            string type, vehicleType;
            ss >> type >> vehicleType;
            if (parkingLot)
            {
                parkingLot->display(type, vehicleType);
            }
            else
            {
                cout << "Parking lot not created yet!" << endl;
            }
        }
    }

    delete parkingLot;
    return 0;
}
