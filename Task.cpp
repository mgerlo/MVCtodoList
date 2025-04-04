#include "Task.h"

Task::Task(const string &desc, const string &d, const string &t, int p, bool c) : description(desc), date(d), time(t),
                                                                                  priority(p),
                                                             done(c) {}

void Task::printTask() const {
    cout << "Description: " << description << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Priority: " << priority << endl;
    cout << "Done: " << (done ? "Yes" : "No") << endl;
}

