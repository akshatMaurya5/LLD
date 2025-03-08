#ifndef DATABASE_LOGGER_CPP
#define DATABASE_LOGGER_CPP

#include <string>
#include "LogDestination.cpp"
#include <iostream>
#include <fstream>
using namespace std;

class DatabaseLogger : public LogDestination
{
public:
    void logMessage(const string &message) override
    {
        cout << "[DATABASE]: " << message << endl;
    }
};

#endif
