#include "TrafficController.cpp"

#include <iostream>

using namespace std;

int main()
{
    TrafficController *controller = TrafficController::getInstance();

    Road *road1 = new Road(1, "Road 1");
    Road *road2 = new Road(2, "Road 2");

    TrafficLight *light1 = new TrafficLight(1, 5, 2, 3, road1);
    TrafficLight *light2 = new TrafficLight(2, 4, 1, 2, road2);

    controller->addRoad(road1);
    controller->addRoad(road2);
    controller->addTrafficLight(light1);
    controller->addTrafficLight(light2);

    cout << "Starting Traffic Signal System...\n";

    controller->startTrafficControl();

    return 0;
}
