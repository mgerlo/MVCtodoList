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

void Model::addList(const TodoList &list) {
    lists.push_back(list);
    notify();
}

void Model::removeListByName(const string &name) {
    auto it = lists.begin();
    bool removed = false;

    while (it != lists.end()) {
        if (it->getNameList() == name) {
            it = lists.erase(it);
            removed = true;
        } else {
            ++it;
        }
    }

    if (removed)
        notify();
}
