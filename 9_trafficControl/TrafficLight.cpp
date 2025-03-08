#ifndef TRAFFIC_LIGHT_CPP
#define TRAFFIC_LIGHT_CPP

#include <iostream>
#include <thread>
#include <chrono>
#include "Signal.cpp"
#include "Road.cpp"

using namespace std;

class TrafficLight
{
private:
    int id;
    Signal currentSignal;
    int redDuration, yellowDuration, greenDuration;
    Road *associatedRoad;

public:
    TrafficLight(int lightId, int redTime, int yellowTime, int greenTime, Road *road) : id(lightId), associatedRoad(road), redDuration(redTime), yellowDuration(yellowTime), greenDuration(greenTime), currentSignal(Signal::RED) {}

    void changeSignal(Signal signal)
    {
        currentSignal = signal;
        associatedRoad->updateSignal(signal);
    }

    void sleep_now(int duration)
    {
        std::this_thread::sleep_for(std::chrono::seconds(duration));
    }

    void startTrafficCycle()
    {
        while (true)
        {
            changeSignal(Signal::GREEN);
            sleep_now(greenDuration);

            changeSignal(Signal::YELLOW);
            sleep_now(yellowDuration);

            changeSignal(Signal::RED);
            sleep_now(redDuration);
        }
    }
};

#endif