#include <bits/stdc++.h>
using namespace std;

enum class LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
};

string logLevelToString(LogLevel level)
{
    switch (level)
    {
    case LogLevel::DEBUG:
        return "DEBUG";
    case LogLevel::INFO:
        return "INFO";
    case LogLevel::WARNING:
        return "WARNING";
    case LogLevel::ERROR:
        return "ERROR";
    case LogLevel::FATAL:
        return "FATAL";
    default:
        return "UNKNOWN";
    }
}

class LogOutput
{
public:
    virtual void write(string message) = 0;
};

class ConsoleOutput : public LogOutput
{
public:
    void write(string message)
    {
        cout << message << endl;
    }
};
class FileOutput : public LogOutput
{
public:
    string filename;
    ofstream file;

    FileOutput(string filename) : filename(filename)
    {
        file.open(filename, ios::app);
    }

    void write(string message)
    {
        file << message << endl;
    }

    ~FileOutput()
    {
        if (file.is_open())
        {
            file.close();
        }
    }
};

class DatabaseOutput : public LogOutput
{
public:
    void write(string message)
    {
        cout << "[DB] " << message << endl;
    }
};

class Logger
{
private:
    time_t getTimeStamp()
    {
        time_t now = time(0);
        return now;
    }

    string getFormattedMessage(LogLevel level, string message)
    {
        time_t timestamp = getTimeStamp();
        string timestampStr = ctime(&timestamp);
        return "[" + timestampStr.substr(0, timestampStr.size() - 1) + "] [" + logLevelToString(level) + "] " + message;
    }

    LogLevel logLevel;
    vector<LogOutput *> outputs;

public:
    Logger() : logLevel(LogLevel::INFO) {}

    void setLogLevel(LogLevel level)
    {
        this->logLevel = level;
    }

    void addOutput(LogOutput *output)
    {
        outputs.push_back(output);
    }

    void log(LogLevel level, string message)
    {
        if (level < logLevel)
            return;

        string logMessage = getFormattedMessage(level, message);

        for (auto output : outputs)
        {
            output->write(logMessage);
        }
    }
};

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     freopen("error.txt", "w", stderr);
    // #endif

    Logger logger;

    // Add console output
    logger.addOutput(new ConsoleOutput());

    // Add file output
    logger.addOutput(new FileOutput("log.txt"));

    // Add database output (stub)
    logger.addOutput(new DatabaseOutput());

    // Set log level to DEBUG
    logger.setLogLevel(LogLevel::DEBUG);

    // Log messages
    logger.log(LogLevel::DEBUG, "This is a debug message.");
    logger.log(LogLevel::INFO, "This is an info message.");
    logger.log(LogLevel::WARNING, "This is a warning message.");
    logger.log(LogLevel::ERROR, "This is an error message.");
    logger.log(LogLevel::FATAL, "This is a fatal message.");

    return 0;
}