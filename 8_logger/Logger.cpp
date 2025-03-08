#ifndef LOGGER_CPP
#define LOGGER_CPP

#include <vector>
#include <mutex>
#include <ctime>
#include <sstream>
#include "LogLevel.cpp"
#include "LogDestination.cpp"
#include "LoggerConfig.cpp"

using namespace std;

class Logger
{
    vector<LogDestination *> destinations;
    LoggerConfig config;
    // mutex logMutex;

    string getTimeStamp()
    {
        time_t now = time(nullptr);
        tm *localTime = localtime(&now);
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
        return buffer;
    }

public:
    Logger(LogLevel level = LogLevel::INFO) : config(level) {}

    void addDestination(LogDestination *destination)
    {
        destinations.push_back(destination);
    }

    void setLogLevel(LogLevel level)
    {
        config.setLogLevel(level);
    }

    void log(LogLevel level, const string &message)
    {
        if (level < config.getLogLevel())
            return;

        // lock_guard<mutex> lock(logMutex);
        std::ostringstream logMsg;

        logMsg << getTimeStamp() << " [" << logLevelToString(level) << "] " << message << endl;

        for (auto destination : destinations)
        {
            destination->logMessage(logMsg.str());
        }
    }

    ~Logger()
    {
        for (auto dest : destinations)
        {
            delete dest;
        }
    }
};

#endif