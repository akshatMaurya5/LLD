#ifndef CONSOLE_LOGGER_CPP
#define CONSOLE_LOGGER_CPP

#include <string>
#include "LogDestination.cpp"
#include <iostream>

using namespace std;

class ConsoleLogger : public LogDestination
{
public:
    void logMessage(const string &message) override
    {
        cout << message << endl;
    }
};

#endif
