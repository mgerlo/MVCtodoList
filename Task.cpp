#include "Task.h"

Task::Task(const string &desc, const string &d, const string &t, int p, bool c) : description(desc), date(d), time(t),
                                                                                  priority(p), done(c) {

    // Regex per orario HH:MM con (00-23):(00-59)
    regex regexTime = checkTime();

    // Regex per data DD-MM-YYYY con (01-31)-(01-12)-YYYY seguendo le regole del CALENDARIO GREGORIANO
    if (!isValidDate(d)) {
        date = "0";
        throw invalid_argument(
                "Data non valida. Usare DD-MM-YYYY con giorno 01-31 e mese 01-12 (calendario Gregoriano). Oppure solo 0 per indicare nessuna data");
    }

    if (!regex_match(t, regexTime)) {
        time = "0";
        throw invalid_argument(
                "Formato orario non valido. Usare HH:MM con ore 00-23 e minuti 00-59. Oppure solo 0 per indicare nessun orario");
    }
}

void Task::setDate(const string &d) {
    if (isValidDate(d)) {
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

bool Task::isValidDate(const string &d) {
    // Regex per data DD-MM-YYYY con (01-31)-(01-12)-YYYY oppure solo 0 per indicare nessuna data
    regex regexDate(R"(^(0|(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-\d{4})$)");
    if (!regex_match(d, regexDate))
        return false;
    if (d == "0")
        return true;    // '0' è valido per indicare 'nessuna data'

    int day = stoi(d.substr(0, 2));
    int month = stoi(d.substr(3, 2));
    int year = stoi(d.substr(6, 4));

    // Mesi con 31 giorni
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return day >= 1 && day <= 31;

        // Mesi con 30 giorni
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return day >= 1 && day <= 30;

        // Febbraio con controllo anno bisestile
    else if (month == 2) {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (isLeap)
            return day >= 1 && day <= 29;
        else
            return day >= 1 && day <= 28;
    }
    return false;       // Mese out-of-range
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
