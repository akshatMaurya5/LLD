#include "Logger.cpp"
#include "ConsoleLogger.cpp"
#include "FileLogger.cpp"
#include "DatabaseLogger.cpp"
#include <string>
using namespace std;

int main()
{
    Logger logger(LogLevel::INFO);
    logger.setLogLevel(LogLevel::DEBUG);

    logger.addDestination(new ConsoleLogger());
    logger.addDestination(new FileLogger("logs.txt"));
    logger.addDestination(new DatabaseLogger());

    string debugMsg = "This is a debug message.";
    string infoMsg = "System started successfully.";
    string warningMsg = "Disk space running low.";
    string errorMsg = "Failed to open configuration file.";
    string fatalMsg = "System crash detected!";

    logger.log(LogLevel::DEBUG, debugMsg);
    logger.log(LogLevel::INFO, infoMsg);
    logger.log(LogLevel::WARNING, warningMsg);
    logger.log(LogLevel::ERROR, errorMsg);
    logger.log(LogLevel::FATAL, fatalMsg);

    return 0;
}
