#ifndef LOG_DESTINATION_CPP
#define LOG_DESTINATION_CPP

#include <string>
using namespace std;

class LogDestination
{
public:
    virtual void logMessage(const string &message) = 0;
    virtual ~LogDestination() {}
};

#endif
