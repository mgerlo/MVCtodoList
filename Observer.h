#ifndef TODOLIST_OBSERVER_H
#define TODOLIST_OBSERVER_H


class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;
};


#endif //TODOLIST_OBSERVER_H
