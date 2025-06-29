#include "ToDoListView.h"

ToDoListView::ToDoListView(wxWindow *parent, Model *model, Controller *controller)
        : View(parent), model(model), controller(controller) {
    model->addObserver(this);
    txtNumLists->SetValue("0");
    txtNumTasks->SetValue("0");
    txtNumDone->SetValue("0");
}

void ToDoListView::onNewListClick(wxCommandEvent &event) {
    string name = txtListName->GetValue().ToStdString();
    if (!name.empty()) {
        controller->newList(name);
        txtListName->Clear(); // Pulisce il campo dopo inserimento
    }
}

void ToDoListView::onNewTaskClick(wxCommandEvent &event) {
    string desc = txtDesc->GetValue().ToStdString();
    if (!desc.empty()) {
        string date = txtDate->GetValue().ToStdString();
        if (date.empty())
            date = "0";
        string time = txtTime->GetValue().ToStdString();
        if (time.empty())
            time = "0";
        string priorityStr = txtPriority->GetValue().ToStdString();
        if (priorityStr.empty())
            priorityStr = "0";
        bool done = checkBoxDone->IsChecked();
        int priority = 0;
        try {
            priority = std::stoi(priorityStr);
        } catch (...) {
            priority = 0;  // default
        }
        controller->addNewTask(desc, date, time, priority, done);
        txtDesc->Clear();
        txtDate->Clear();
        txtTime->Clear();
        txtPriority->Clear();
        checkBoxDone->SetValue(false);
        txtDesc->SetFocus();
    }
}

void ToDoListView::onRemoveListClick(wxCommandEvent &event) {
    string name = txtRemoveName->GetValue().ToStdString();
    if (!name.empty()) {
        controller->removeList(name);
        txtRemoveName->Clear();
    }
}

void ToDoListView::update() {
    txtNumLists->SetValue(to_string(model->getLists().size()));

    int total = 0, countDone = 0;
    for (const auto &l: model->getLists()) {
        total += l.numTotTask();
        countDone += l.numDone();
    }
    txtNumTasks->SetValue(to_string(total));
    txtNumDone->SetValue(to_string(countDone));
}

ToDoListView::~ToDoListView() {
    if (model)
        model->removeObserver(this);
}
