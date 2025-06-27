#include "Controller.h"

void Controller::newList(const string &name) {
    if (!name.empty()) {
        TodoList newList(name); // Crea nuova lista con nome
        model->addList(newList); // Aggiunge al Modello
    }
}

void Controller::removeList(const string &name) {
    if (!name.empty()) {
        model->removeListByName(name);
    }
}
