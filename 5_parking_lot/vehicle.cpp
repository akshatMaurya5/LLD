#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
    string type;
    string regNo;
    string color;

    Vehicle(string type, string regNo, string color)
    {
        this->type = type;
        this->regNo = regNo;
        this->color = color;
    }
};
