**Sprint Planner**

**Description**

Design a Sprint planner (Similar to Jira). A Sprint planner is used to assign the task to the team member and check the progress of the project of each teammate which is assigned to him/her.

- **Sprint:** This is a time period in which the company assigns a task to the employee/team to complete a set amount of work.
- **Task:** This comes inside the sprint, where any new feature of the project is broken down into a task, which is assigned to the team member.

**Functionalities of the Sprint Planner:**

1. Users should be able to create any Sprint. Should be able to add any Task to the Sprint and remove from it.
2. Users should be able to create a Task of type Story, Feature, Bug. Each can have their own Status (TODO, INPROGRESS, DONE).
3. Users should be able to change the Status of a Task.
4. Show Tasks assigned to a User in the Sprint.

---

**Constraints:**

- Users can have max 2 Tasks in INPROGRESS Status in a Sprint.
- Sprint can have max 20 Tasks.
- Following Status changes are allowed (TODO -> INPROGRESS, INPROGRESS->TODO, INPROGRESS-> DONE).

**Expectations:**

1. Make sure that you have a working and demonstrable code
2. Make sure that the code is functionally correct
3. Make sure that the code is readable and modular (Code quality)
4. Make sure that the code is thread safe
5. Get Delayed Tasks in the Sprint.


**My Plan**

- Task Class
    - type -  story, feature, bug
    - status - Todo, inProgress, Done

- User
    - no. of active tasks
    - max 2 tasks in progess at any moment

- Sprint
    - has tasks[]
    - limit of 20 tasks per print
    - track delayed tasks
