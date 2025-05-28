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

    /*int getNum() const {
        return numLists;
    }*/

    //void setNum(int n);

    const list<TodoList> &getLists() const {
        return lists;
    }

    void addList(const TodoList &list);

private:
    //int numLists = 0;     // non serve perché si può usare size() sulle liste
    list<TodoList> lists;
    list<Observer *> observers;
};


#endif //TODOLIST_MODEL_H
