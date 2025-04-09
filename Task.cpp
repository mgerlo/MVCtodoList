#include "Task.h"

Task::Task(const string &desc, const string &d, const string &t, int p, bool c) : description(desc), date(d), time(t),
                                                                                  priority(p), done(c) {
    // Regex per data (DD-MM-YYYY) e orario (HH:MM)
    regex regexDate(R"(^\d{2}-\d{2}-\d{4}$)");
    regex regexTime(R"(^\d{2}:\d{2}$)");

    if (!regex_match(d, regexDate)) {
        date = "01-01-2025";
        throw invalid_argument("Formato data non valido. Usare DD-MM-YYYY");
    }

    if (!regex_match(t, regexTime)) {
        time = "10:00";
        throw invalid_argument("Formato orario non valido. Usare HH:MM");
    }
}

void Task::setDate(const string &d) {
    // Regex per data (DD-MM-YYYY)
    regex regexDate(R"(^\d{2}-\d{2}-\d{4}$)");
    if (regex_match(d, regexDate)) {
        date = d;
    }
}

void Task::setTime(const string &t) {
    // Regex per orario (HH:MM)
    regex regexTime(R"(^\d{2}:\d{2}$)");
    if (regex_match(t, regexTime)) {
        time = t;
    }
}

void Task::printTask() const {
    cout << "Description: " << description << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Priority: " << priority << endl;
    cout << "Done: " << (done ? "Yes" : "No") << endl;
}

