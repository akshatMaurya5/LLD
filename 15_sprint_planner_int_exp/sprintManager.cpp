#ifndef SPRINTMANAGER_H
#define SPRINTMANAGER_H

#include "sprint.cpp"

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class SprintManager
{
private:
    unordered_map<string, Sprint> sprints;

public:
    // SprintManager()
    // {
    //     sprints.clear();
    // }
    SprintManager() = default;

    void createSprint(string name)
    {
        Sprint sprint(name);
        // sprints[sprint.getId()] = sprint;
        sprints.emplace(sprint.getId(), sprint);
        cout << "Sprint created successfully" << endl;
    }

    Sprint *getSprint(const string &sprintId)
    {
        auto it = sprints.find(sprintId);
        return (it != sprints.end()) ? &it->second : nullptr;
    }

    unordered_map<std::string, Sprint> &getAllSprints()
    {
        return sprints;
    }
};

#endif