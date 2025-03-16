#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <iostream>
#include <string>

using namespace std;

class Task {
public:
    explicit Task(string desc = "Activity", string d = "today", string t = "10:00 AM", int p = 0, bool c = false);

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &desc) {
        description = desc;
    }

    const string &getDate() const {
        return date;
    }

    void setDate(const string &d) {
        date = d;
    }

    const string &getTime() const {
        return time;
    }

    void setTime(const string &t) {
        time = t;
    }

    int getPriority() const {
        return priority;
    }

    void setPriority(int p) {
        priority = p;
    }

    bool isDone() const {
        return done;
    }

    void setDone(bool c) {
        done = c;
    }

    void printTask() const;

private:
    string description;
    string date;
    string time;
    int priority;
    bool done;
};


#endif //TODOLIST_TASK_H
