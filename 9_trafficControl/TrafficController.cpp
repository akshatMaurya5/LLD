#ifndef TRAFFIC_CONTROLLER_CPP
#define TRAFFIC_CONTROLLER_CPP

#include "TrafficLight.cpp"
#include <vector>
#include <thread>

using namespace std;

class TrafficController
{
private:
    vector<Road *> roads;
    vector<TrafficLight *> trafficLights;
    static TrafficController *instance;

    TrafficController() {}

public:
    static TrafficController *getInstance()
    {
        if (!instance)
        {
            instance = new TrafficController();
        }
        return instance;
    }

    void addRoad(Road *road)
    {
        roads.push_back(road);
    }

    void addTrafficLight(TrafficLight *light)
    {
        trafficLights.push_back(light);
    }

    void startTrafficControl()
    {
        for (auto light : trafficLights)
        {
            // light->startTrafficCycle();
            std::thread t(&TrafficLight::startTrafficCycle, light);
            t.detach();
        }
    }
};
TrafficController *TrafficController::instance = nullptr;
#endif
