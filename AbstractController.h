#ifndef TODOLIST_ABSTRACTCONTROLLER_H
#define TODOLIST_ABSTRACTCONTROLLER_H

#include <string>

using namespace std;

class AbstractController {
public:
    virtual ~AbstractController() = default;

    virtual void newList(const string &name) = 0;

    virtual void removeList(const string &name) = 0;
};


#endif //TODOLIST_ABSTRACTCONTROLLER_H
