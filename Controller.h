#ifndef TODOLIST_CONTROLLER_H
#define TODOLIST_CONTROLLER_H

#include "AbstractController.h"
#include "Model.h"

class Controller : public AbstractController {
public:
    explicit Controller(Model *m) : model(m) {}

    void newList(const string &name) override;

    void removeList(const string &name) override;

    void addNewTask(const string &desc, const string &date, const string &time, int priority, bool done) override;

    Model *getModel() const {
        return model;
    }

private:
    Model *model;
};


#endif //TODOLIST_CONTROLLER_H
