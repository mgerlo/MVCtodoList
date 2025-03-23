#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <list>
#include "Task.h"

using namespace std;

class TodoList {
public:
    list<Task> getTasks() const {
        return tasks;
    }

    void setTask(const Task &task) {
        tasks.push_back(task);
    }

    void printTodoList() const;

private:
    list<Task> tasks;
};


#endif //TODOLIST_TODOLIST_H
