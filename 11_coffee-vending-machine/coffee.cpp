#include "coffee.hpp"

Coffee::Coffee(CoffeeType type, double price, string description) : type(type), price(price), description(description) {}

CoffeeType Coffee::getType() const
{
    return type;
}

double Coffee::getPrice() const
{
    return price;
}

string Coffee::getDescription() const
{
    return description;
}
