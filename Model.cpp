#include "Model.h"

void Model::notify() {
    for (auto observer: observers)
        observer->update();
}

void Model::addObserver(Observer *o) {
    observers.push_back(o);
}

void Model::removeObserver(Observer *o) {
    observers.remove(o);
}

void Model::setNum(const int n) {
    numLists = n;
    notify();
}

void Model::setList(const TodoList &list) {
    lists.push_back(list);
    int value = getNum();
    value++;
    setNum(value);
}
