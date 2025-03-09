#include "sprintManager.cpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "Creating Sprint Manager and Sprint..." << endl;
    SprintManager manager;
    manager.createSprint("Sprint 1");

    Sprint *sprint = nullptr;
    for (auto &it : manager.getAllSprints())
    {
        sprint = &it.second;
        break;
    }

    if (sprint)
    {
        cout << "\nCreating tasks..." << endl;
        // Create tasks
        Task task1("T1", "Implement Login", TaskType::FEATURE);
        Task task2("T2", "Fix Logout Bug", TaskType::BUG);
        Task task3("T3", "Add User Story", TaskType::STORY);

        // Add tasks to sprint with users
        cout << "\nAdding tasks to sprint:" << endl;
        cout << "Adding task T1 to user U1..." << endl;
        sprint->addTask(task1, "U1");
        cout << "Adding task T2 to user U1..." << endl;
        sprint->addTask(task2, "U1");
        cout << "Adding task T3 to user U2..." << endl;
        sprint->addTask(task3, "U2");

        cout << "\nChanging task statuses:" << endl;
        cout << "Setting T1 to IN_PROGRESS..." << endl;
        sprint->changeTaskStatus("T1", TaskStatus::IN_PROGRESS);
        cout << "Setting T2 to IN_PROGRESS..." << endl;
        sprint->changeTaskStatus("T2", TaskStatus::IN_PROGRESS);
        cout << "Setting T3 to IN_PROGRESS (should fail as U1 has max tasks)..." << endl;
        sprint->changeTaskStatus("T3", TaskStatus::IN_PROGRESS);

        cout << "\nChecking delayed tasks:" << endl;
        sprint->getDealyedTasks();
    }
    else
    {
        cout << "Failed to create sprint!" << endl;
    }

    return 0;
}
