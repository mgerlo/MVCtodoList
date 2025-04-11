#include "TodoList.h"

TodoList::TodoList(const string &name) : nameList(name) {}

bool TodoList::removeTask(const Task &t) {
    auto dim = tasks.size();
    tasks.remove(t);
    return dim > tasks.size();      // return true se c'è stata effettiva rimozione
}

int TodoList::numTotTask() const {
    auto n = tasks.size();
    return static_cast<int>(n);
}

/*
void TodoList::printTodoList() const {
    if (tasks.empty())
        cout << " List is empty !" << endl;
    else {
        cout << " List:" << endl;
        for (auto &task: tasks) {
            cout << "----------" << endl;
            task.printTask();
        }
    }
}
*/
