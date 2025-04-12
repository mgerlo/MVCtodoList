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

    bool removeTask(const Task &t);     // cancellare() Task

    int numTotTask() const;     // contare() il numero totale di Tasks

    int numNotDone() const;     // contare() il numero totale di Tasks NON COMPLETATI

    int numDone() const;        // contare() il numero totale di Tasks COMPLETATI

    int numTaskDate(const string &data) const;      // contare() il numero di Tasks con una certa data

    int numTaskPriority(int p) const;       // contare() il numero di Tasks con una certa priorità

    list<Task> getNotDone() const;      // prendere() tutti i Tasks NON COMPLETATI

    list<Task> getDone() const;     // prendere() tutti i Tasks COMPLETATI

    list<Task> searchTask(const string &desc) const;    // cercare() i Tasks con una descrizione

    //void printTodoList() const;     // remove print() in presenza di GUI, responsabilità della vista

private:
    string nameList;
    list<Task> tasks;
};


#endif //TODOLIST_TODOLIST_H
