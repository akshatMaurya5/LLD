#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

// Constants
const double BASE_FARE = 50.0;
const double PER_KM_RATE = 10.0;
const double EARTH_RADIUS = 6371.0; // In kilometers

class Location
{
public:
    double latitude, longitude;

    Location(double lat = 0, double lon = 0) : latitude(lat), longitude(lon) {}

    double distanceTo(const Location &other)
    {
        double latDiff = (other.latitude - latitude) * M_PI / 180.0;
        double lonDiff = (other.longitude - longitude) * M_PI / 180.0;

        double a = sin(latDiff / 2) * sin(latDiff / 2) +
                   cos(latitude * M_PI / 180.0) * cos(other.latitude * M_PI / 180.0) *
                       sin(lonDiff / 2) * sin(lonDiff / 2);

        double c = 2 * atan2(sqrt(a), sqrt(1 - a));

        return EARTH_RADIUS * c;
    }
};

class User
{
public:
    int id;
    string name;
    Location location;

    User(int uid, string uname, Location uloc)
    {
        this->id = uid;
        this->name = uname;
        this->location = uloc;
    }

    void updateLocation(Location newLocation)
    {
        location = newLocation;
    }
};

class Cab
{
public:
    string vehicleId, model, number;

    Cab(string vid, string mdl, string num)
    {
        this->vehicleId = vid;
        this->model = mdl;
        this->number = num;
    }
};

class Driver : public User
{
public:
    bool isAvailable;
    Cab *cab;

    Driver(int uid, string name, Location loc, Cab *vehicle) : User(uid, name, loc)
    {
        this->cab = vehicle;
        this->isAvailable = true;
    }

    void setAvailability(bool availability)
    {
        isAvailable = availability;
    }
};

class Rider : public User
{
public:
    Rider(int uid, string uname, Location loc) : User(uid, uname, loc) {}
};

class Ride
{
public:
    Rider *rider;
    Driver *driver;
    Location source, destination;
    bool isCompleted;
    double fare;

    Ride(Rider *r, Driver *d, Location src, Location dest)
    {
        this->rider = r;
        this->driver = d;
        this->source = src;
        this->destination = dest;
        this->isCompleted = false;
        this->fare = 0.0;
    }

    void startRide()
    {
        cout << "Ride started with driver:" << driver->name << endl;
        driver->setAvailability(false);
    }

    void completeRide()
    {
        double distanceCovered = source.distanceTo(destination);
        fare = BASE_FARE + distanceCovered * PER_KM_RATE;
        isCompleted = true;
        driver->setAvailability(true);
        cout << "Ride completed with fare:" << fare << endl;
    }
};

class CabBookingSystem
{
private:
    map<int, Rider *> riders;
    map<int, Driver *> drivers;
    map<int, Ride *> rides;
    int ridesCounter = 1;

public:
    void addRider(Rider *rider)
    {
        riders[rider->id] = rider;
    }

    void addDriver(Driver *driver)
    {
        drivers[driver->id] = driver;
    }

    void updateDriverLocation(int driverId, double latitude, double longitude)
    {
        if (drivers.count(driverId))
        {
            drivers[driverId]->location = Location(latitude, longitude);
            cout << "Driver " << drivers[driverId]->name << "'s location updated.\n";
        }
        else
        {
            cout << "Driver not found.\n";
        }
    }

    void updateRiderLocation(int riderId, double latitude, double longitude)
    {
        if (riders.count(riderId))
        {
            riders[riderId]->location = Location(latitude, longitude);
            cout << "Rider" << riders[riderId]->name << "'s location updated.\n";
        }
        else
        {
            cout << "Rider not found.\n";
        }
    }

    Driver *findNearestDriver(Location riderLocation)
    {
        Driver *nearestDriver = nullptr;
        double minDistance = 1e5;

        for (auto pair : drivers)
        {
            Driver *driver = pair.second;
            if (driver->isAvailable)
            {
                double distance = riderLocation.distanceTo(driver->location);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    nearestDriver = driver;
                }
            }
        }
        return nearestDriver;
    }

    void bookRide(int riderId, Location destination)
    {

        if (!riders.count(riderId))
        {
            cout << "Rider not found.\n";
            return;
        }

        Rider *rider = riders[riderId];

        Driver *driver = findNearestDriver(rider->location);

        if (!driver)
        {
            cout << "No available driver nearby.\n";
            return;
        }

        Ride *ride = new Ride(rider, driver, rider->location, destination);

        rides[ridesCounter++] = ride;
        cout << "Ride booked successfully.\n";

        ride->startRide();

        cout << "Travelling........" << endl;

        ride->completeRide();
    }
};

int main()
{

    CabBookingSystem system;

    Rider *rider1 = new Rider(1, "Alice", Location(12.9716, 77.5946));
    system.addRider(rider1);

    Cab *cab1 = new Cab("KA01AB1234", "Toyota", "1234");
    Driver *driver1 = new Driver(101, "Bob", Location(12.9700, 77.5950), cab1);
    system.addDriver(driver1);

    Cab *cab2 = new Cab("KA02CD5678", "Honda", "5678");
    Driver *driver2 = new Driver(102, "Charlie", Location(12.9600, 77.5800), cab2);
    system.addDriver(driver2);

    system.updateDriverLocation(101, 12.9710, 77.5930);
    system.updateRiderLocation(1, 12.9720, 77.5940);

    system.bookRide(1, Location(12.9500, 77.5800));

    return 0;
}