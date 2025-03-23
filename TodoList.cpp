#include "TodoList.h"

void TodoList::printTodoList() const {
    if (tasks.empty())
        cout << "ToDo List is empty !" << endl;
    else {
        cout << "ToDo List:" << endl;
        for (auto &task: tasks) {
            cout << "----------" << endl;
            task.printTask();
        }
    }
}
