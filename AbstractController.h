#ifndef TODOLIST_ABSTRACTCONTROLLER_H
#define TODOLIST_ABSTRACTCONTROLLER_H

#include <string>

using namespace std;

class AbstractController {
public:
    virtual ~AbstractController() = default;

    virtual void newList(const string &name) = 0;

    virtual void removeList(const string &name) = 0;

    virtual void addNewTask(const string &desc, const string &date, const string &time, int priority, bool done) = 0;
};


#endif //TODOLIST_ABSTRACTCONTROLLER_H
