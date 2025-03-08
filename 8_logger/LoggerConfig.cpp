#ifndef LOGGER_CONFIG_CPP
#define LOGGER_CONFIG_CPP

#include "LogLevel.cpp"

class LoggerConfig
{
    LogLevel minLevel;

public:
    LoggerConfig(LogLevel level) : minLevel(INFO) {}

    void setLogLevel(LogLevel level)
    {
        minLevel = level;
    }

    LogLevel getLogLevel() const
    {
        return minLevel;
    }
};

#endif
