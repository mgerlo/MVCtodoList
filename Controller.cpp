#include "Controller.h"

void Controller::newList(const string &name) {
    if (!name.empty()) {
        TodoList newL(name); // Crea nuova lista con nome
        model->addList(newL); // Aggiunge al Modello
    }
}

void Controller::removeList(const string &name) {
    if (!name.empty()) {
        model->removeListByName(name);
    }
}

void Controller::addNewTask(const string &desc, const string &date, const string &time, int priority, bool done) {
    if (!desc.empty()) {
        Task t(desc, date, time, priority, done);
        model->addTaskToLastList(t);  // delega al Model
    }
}
