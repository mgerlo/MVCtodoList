#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <list>
#include <algorithm>
#include "Task.h"

using namespace std;

class TodoList {
public:
    explicit TodoList(const string &name = "New List");

    const string &getNameList() const {
        return nameList;
    }

    void setNameList(const string &name) {
        nameList = name;
    }

    const list<Task> &getTasks() const {    // ...forse utilizzato per la GUI
        return tasks;
    }

    void addTask(const Task &task) {
        tasks.push_back(task);
    }

    bool removeTask(const Task &t);

    int numTotTask() const;

    int numNotDone() const;

    int numDone() const;

    //void printTodoList() const;     // remove print() in presenza di GUI, responsabilità della vista

private:
    string nameList;
    list<Task> tasks;
};


#endif //TODOLIST_TODOLIST_H
