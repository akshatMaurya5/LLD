# Logging Framework Design

## Requirements

1. **Log Levels**: The logging framework should support different log levels:
   - DEBUG
   - INFO
   - WARNING
   - ERROR
   - FATAL

2. **Log Messages**: It should allow logging messages with:
   - Timestamp
   - Log level
   - Message content

3. **Output Destinations**: The framework should support multiple output destinations:
   - Console
   - File
   - Database

4. **Configuration**: It should provide a configuration mechanism to:
   - Set the log level
   - Set the output destination

5. **Thread Safety**: The logging framework should be thread-safe to handle concurrent logging from multiple threads.

6. **Extensibility**: It should be extensible to accommodate new log levels and output destinations in the future.

## Example Code

### Logger.h

- FLOW
- LOGLEVEL
- LOGDESTINATION
- ConsoleLogger
- FileLogger
- DatabaseLogger
- LoggerConfig.cpp
- Logger.cpp
- main.cpp

Take away from fileLogger
```

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
```