#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <iostream>
#include <string>
#include <regex>
//#include <stdexcept>

using namespace std;

class Task {
public:
    explicit Task(const string &desc = "Activity", const string &d = "01-01-2025", const string &t = "10:00", int p = 0,
                  bool c = false);      // testare il costruttore,
    // se si passano valori come "Pippo" o "Paperino", lancia un'eccezione
    // in fase di impostazione (costruttore) controllare con un regex che il formato sia corretto

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &desc) {
        description = desc;
    }

    const string &getDate() const {
        return date;
    }

    void setDate(const string &d);     // (set) controllare con un regex che il formato sia corretto

    const string &getTime() const {
        return time;
    }

    void setTime(const string &t);     // (set) controllare con un regex che il formato sia corretto

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

    bool operator==(const Task &r) const;   // sovraccaricamento operatore == per Task

    regex checkDate();

    regex checkTime();

    //void printTask() const;     // remove print() in presenza di GUI, responsabilità della vista

private:
    string description;
    string date;    // use regex (STL) per controllare forma / formato della stringa passata nei setter e nel costruttore
    string time;    // use regex ... (garantire che date sia sempre una data e time sia sempre un orario)
    int priority;
    bool done;
};


#endif //TODOLIST_TASK_H
