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

int TodoList::numNotDone() const {
    auto n = count_if(tasks.begin(), tasks.end(), [](const Task &t) -> bool {
        return !t.isDone();
    });
    return static_cast<int>(n);
}

int TodoList::numDone() const {
    auto n = count_if(tasks.begin(), tasks.end(), [](const Task &t) -> bool {
        return t.isDone();
    });
    return static_cast<int>(n);
}

int TodoList::numTaskDate(const std::string &data) const {
    auto n = count_if(tasks.begin(), tasks.end(), [data](const Task &t) -> bool {
        return t.getDate() == data;
    });
    return static_cast<int>(n);
}

int TodoList::numTaskPriority(int p) const {
    auto n = count_if(tasks.begin(), tasks.end(), [p](const Task &t) -> bool {
        return t.getPriority() == p;
    });
    return static_cast<int>(n);
}

list<Task> TodoList::getNotDone() const {
    list<Task> notDone;
    copy_if(tasks.begin(), tasks.end(), back_inserter(notDone), [](const Task &t) -> bool {
        return !t.isDone();
    });
    return notDone;
}

list<Task> TodoList::getDone() const {
    list<Task> done;
    copy_if(tasks.begin(), tasks.end(), back_inserter(done), [](const Task &t) -> bool {
        return t.isDone();
    });
    return done;
}

list<Task> TodoList::searchTask(const std::string &desc) const {
    list<Task> results;
    copy_if(tasks.begin(), tasks.end(), back_inserter(results), [desc](const Task &t) -> bool {
        return t.getDescription() == desc;
    });
    return results;
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
