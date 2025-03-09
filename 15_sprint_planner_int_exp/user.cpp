#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
#include "task.cpp"

using namespace std;

class User
{

private:
    string id;
    string name;
    int activeTasks;
    vector<Task> tasks;
    static int userIdCounter;

public:
    // Default constructor
    User() : id(""), name(""), activeTasks(0) {}

    User(string name)
    {
        this->id = "U" + to_string(userIdCounter++);
        this->name = name;
        this->activeTasks = 0;
    }

    string getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    int getActiveTasks() const
    {
        return activeTasks;
    }

    bool canTakeMoreInProgressTasks() const
    {
        return activeTasks < 2;
    }

    void addTask(Task task)
    {
        if (task.getStatus() == TaskStatus::IN_PROGRESS)
        {
            activeTasks++;
        }
        tasks.push_back(task);
    }

    void removeTask(string taskId)
    {
        for (auto it = tasks.begin(); it != tasks.end(); it++)
        {
            if (it->getId() == taskId)
            {
                if (it->getStatus() == TaskStatus::IN_PROGRESS)
                {
                    activeTasks--;
                }
                tasks.erase(it);
                break;
            }
        }
    }
};

int User::userIdCounter = 1;

#endif