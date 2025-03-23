#ifndef TODOLIST_SUBJECT_H
#define TODOLIST_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    virtual void notify() = 0;

    virtual void addObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;
};


#endif //TODOLIST_SUBJECT_H
