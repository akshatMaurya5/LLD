#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <set>
// #include<pair>
using namespace std;

enum TaskType
{
    STORY,
    FEATURE,
    BUG
};

enum TaskStatus
{
    TODO,
    IN_PROGRESS,
    DONE
};

class Task
{
private:
    string id;
    string title;
    TaskType type;
    TaskStatus status;
    string assignedUser;

    set<pair<TaskStatus, TaskStatus>> allowedStatusTransitions;

public:
    // Default constructor
    Task() : id(""), title(""), type(TaskType::STORY), status(TaskStatus::TODO), assignedUser("")
    {
        allowedStatusTransitions = {
            {TaskStatus::TODO, TaskStatus::IN_PROGRESS},
            {TaskStatus::IN_PROGRESS, TaskStatus::DONE},
            {TaskStatus::IN_PROGRESS, TaskStatus::TODO}};
    }

    Task(string id, string title, TaskType type)
    {
        this->id = id;
        this->title = title;
        this->type = type;
        this->status = TaskStatus::TODO;
        this->assignedUser = "";

        allowedStatusTransitions = {
            {TaskStatus::TODO, TaskStatus::IN_PROGRESS},
            {TaskStatus::IN_PROGRESS, TaskStatus::DONE},
            {TaskStatus::IN_PROGRESS, TaskStatus::TODO}};
    }

    string getId() const
    {
        return id;
    }

    string getTitle() const
    {
        return title;
    }

    TaskType getType() const
    {
        return type;
    }

    TaskStatus getStatus() const
    {
        return status;
    }

    string getAssignedUser() const
    {
        return assignedUser;
    }

    bool changeStatus(TaskStatus newStatus)
    {
        if (allowedStatusTransitions.count({status, newStatus}))
        {
            cout << "Status changed from " << status << " to " << newStatus << " for task " << id << endl;
            status = newStatus;
            return true;
        }
        cout << "Invalid status transition for task " << id << endl;
        return false;
    }

    void assignUser(string user)
    {
        assignedUser = user;
        cout << "Task " << id << " assigned to user " << user << endl;
    }
};

#endif
