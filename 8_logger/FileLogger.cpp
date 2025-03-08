#ifndef FILE_LOGGER_CPP
#define FILE_LOGGER_CPP

#include <string>
#include "LogDestination.cpp"
#include <iostream>
#include <fstream>
using namespace std;

class FileLogger : public LogDestination
{
    ofstream outFile;

public:
    FileLogger(const string &filename)
    {
        outFile.open(filename, ios::app);
    }

    void logMessage(const string &message) override
    {
        if (outFile.is_open())
        {
            outFile << message << std::endl;
        }
    }

    ~FileLogger()
    {
        if (outFile.is_open())
        {
            outFile.close();
        }
    }
};

#endif