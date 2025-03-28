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
