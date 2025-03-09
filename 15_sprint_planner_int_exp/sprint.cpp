#ifndef SPRINT_H
#define SPRINT_H
#include <iostream>
#include <vector>
#include <string>
#include "task.cpp"
#include "user.cpp"
#include <unordered_map>
#include <stdexcept>

using namespace std;

class Sprint
{
private:
    string sprintId;
    string sprintName;
    unordered_map<string, Task> tasks;
    unordered_map<string, User> users;
    bool isUpdating; // boolean flag for thread safety
    static int sprintIdCounter;

public:
    Sprint() : sprintId(""), sprintName(""), isUpdating(false) {}
    Sprint(string name) : sprintId("S" + to_string(sprintIdCounter++)),
                          sprintName(name),
                          isUpdating(false) {}

    string getId() const
    {
        return sprintId;
    }

    string getName() const
    {
        return sprintName;
    }

    bool addTask(Task task, string userId)
    {
        if (tasks.size() >= 20)
        {
            cout << "Sprint is full" << endl;
            return false;
        }

        if (isUpdating)
        {
            cout << "Sprint is currently being updated" << endl;
            return false;
        }

        isUpdating = true;

        try
        {
            if (users.find(userId) == users.end())
            {
                User user(userId);
                users[userId] = user;
            }

            if (task.getStatus() == TaskStatus::IN_PROGRESS && !users[userId].canTakeMoreInProgressTasks())
            {
                cout << "User cannot take more in progress tasks" << endl;
                isUpdating = false;
                return false;
            }

            task.assignUser(userId);
            tasks[task.getId()] = task;
            users[userId].addTask(task);
            cout << "Task with id " << task.getId() << " successfully added to user " << userId << endl;
        }
        catch (const exception &e)
        {
            cout << "Error adding task: " << e.what() << endl;
            isUpdating = false;
            return false;
        }

        isUpdating = false;
        return true;
    }

    bool removeTask(string taskId)
    {
        if (tasks.find(taskId) == tasks.end())
        {
            cout << "Task not found" << endl;
            return false;
        }

        isUpdating = true;

        try
        {
            auto userId = tasks[taskId].getAssignedUser();
            users[userId].removeTask(taskId);
            tasks.erase(taskId);
            cout << "Task with id " << taskId << " successfully removed" << endl;
        }
        catch (const exception &e)
        {
            cout << "Error removing task: " << e.what() << endl;
        }

        isUpdating = false;
        return true;
    }

    bool changeTaskStatus(string taskId, TaskStatus newStatus)
    {
        if (!tasks.count(taskId))
        {
            cout << "Task not found" << endl;
            return false;
        }

        Task &task = tasks[taskId];
        string userId = task.getAssignedUser();

        if (newStatus == TaskStatus::IN_PROGRESS && !users[userId].canTakeMoreInProgressTasks())
        {
            cout << "User cannot take more in progress tasks" << endl;
            return false;
        }

        isUpdating = true;
        bool statusChanged = task.changeStatus(newStatus);
        isUpdating = false;

        if (statusChanged)
        {
            cout << "Task status changed successfully" << endl;
        }
        else
        {
            cout << "Failed to change task status" << endl;
        }

        return statusChanged;
    }

    void getDealyedTasks()
    {

        for (auto it : tasks)
        {
            auto id = it.first;
            auto task = it.second;
            auto taskId = task.getId();
            auto taskTitle = task.getTitle();
            auto taskStatus = task.getStatus();

            if (taskStatus != TaskStatus::DONE)
            {
                cout << "Task with id " << taskId << " and title " << taskTitle << " is delayed" << endl;
            }
        }
    }
};

int Sprint::sprintIdCounter = 1;

#endif
