#ifndef TODOLIST_ABSTRACTCONTROLLER_H
#define TODOLIST_ABSTRACTCONTROLLER_H


class AbstractController {
public:
    virtual ~AbstractController() = default;

    virtual void addList() = 0;

    virtual void removeList() = 0;
};


#endif //TODOLIST_ABSTRACTCONTROLLER_H
