#ifndef TODOLIST_MODEL_H
#define TODOLIST_MODEL_H

#include <list>
#include "Subject.h"
#include "TodoList.h"

using namespace std;

class Model : public Subject {
public:
    void notify() override;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    list<TodoList> getLists() const {
        return lists;
    }

    void addList(const TodoList &list) {
        lists.push_back(list);
        notify();
    }

private:
    list<TodoList> lists;
    list<Observer *> observers;
};


#endif //TODOLIST_MODEL_H
