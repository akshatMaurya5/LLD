#ifndef SIGNAL_CPP
#define SIGNAL_CPP

#include <iostream>

using namespace std;

enum class Signal
{
    RED,
    YELLOW,
    GREEN
};

string signalToString(Signal signal)
{
    switch (signal)
    {
    case Signal::RED:
        return "RED";
    case Signal::YELLOW:
        return "YELLOW";
    case Signal::GREEN:
        return "GREEN";
    default:
        return "UNKNOWN";
    }
}

#endif
