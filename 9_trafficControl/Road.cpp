#ifndef ROAD_CPP
#define ROAD_CPP

#include "Signal.cpp"
#include <iostream>

using namespace std;

class Road
{
private:
    int id;
    string name;
    Signal currentSignal;

public:
    Road(int id, string name) : id(id), name(name), currentSignal(Signal::RED) {}

    void updateSignal(Signal signal)
    {
        currentSignal = signal;
        cout << "Road " << name << " now has signal" << signalToString(signal) << endl;
    }

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    Signal getCurrentSignal() const
    {
        return currentSignal;
    }
};
#endif
