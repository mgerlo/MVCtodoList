#ifndef TODOLIST_CONTROLLER_H
#define TODOLIST_CONTROLLER_H

#include "AbstractController.h"
#include "Model.h"

class Controller : public AbstractController {
public:
    explicit Controller(Model *m) : model(m) {}

    // TODO override methods

private:
    Model *model;
};


#endif //TODOLIST_CONTROLLER_H
