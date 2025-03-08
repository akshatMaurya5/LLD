#ifndef COFFEE_HPP
#define COFFEE_HPP

#include <string>
#include <vector>
#include "coffee-type.hpp"

using namespace std;

class Coffee
{
private:
    CoffeeType type;
    double price;
    string description;

public:
    Coffee(CoffeeType type, double price, string description);
    CoffeeType getType() const;
    double getPrice() const;
    string getDescription() const;
};

#endif
