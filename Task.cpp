#include "Task.h"

Task::Task(const string &desc, const string &d, const string &t, int p, bool c) : description(desc), date(d), time(t),
                                                                                  priority(p), done(c) {
    // Regex per data DD-MM-YYYY con (01-31)-(01-12)-YYYY
    regex regexDate = checkDate();

    // Regex per orario HH:MM con (00-23):(00-59)
    regex regexTime = checkTime();

    if (!regex_match(d, regexDate)) {
        date = "0";
        throw invalid_argument(
                "Formato data non valido. Usare DD-MM-YYYY con giorno 01-31 e mese 01-12. Oppure solo 0 per indicare nessuna data");
    }

    if (!regex_match(t, regexTime)) {
        time = "0";
        throw invalid_argument(
                "Formato orario non valido. Usare HH:MM con ore 00-23 e minuti 00-59. Oppure solo 0 per indicare nessun orario");
    }
}

void Task::setDate(const string &d) {
    regex regexDate = checkDate();
    if (regex_match(d, regexDate)) {
        date = d;
    }
}

void Task::setTime(const string &t) {
    regex regexTime = checkTime();
    if (regex_match(t, regexTime)) {
        time = t;
    }
}

bool Task::operator==(const Task &r) const {
    return (description == r.getDescription()) &&
           (date == r.getDate()) &&
           (time == r.getTime()) &&
           (priority == r.getPriority()) &&
           (done == r.isDone());
}

regex Task::checkDate() {
    // Regex per data DD-MM-YYYY con (01-31)-(01-12)-YYYY oppure solo 0 per indicare nessuna data
    regex regexDate(R"(^(0|(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-\d{4})$)");
    return regexDate;

    // Regex per data (DD-MM-YYYY)
    //regex regexDate(R"(^\d{2}-\d{2}-\d{4}$)");
}

regex Task::checkTime() {
    // Regex per orario HH:MM con (00-23):(00-59) oppure solo 0 per indicare nessun orario
    regex regexTime(R"(^(0|([01][0-9]|2[0-3]):([0-5][0-9]))$)");
    return regexTime;

    // Regex per orario (HH:MM)
    //regex regexTime(R"(^\d{2}:\d{2}$)");
}

/*
void Task::printTask() const {
    cout << "Description: " << description << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Priority: " << priority << endl;
    cout << "Done: " << (done ? "Yes" : "No") << endl;
}
*/
