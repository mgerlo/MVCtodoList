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
    // controller->newTask(); // da implementare in futuro
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
    //txtNumTasks->SetValue(std::to_string(model->getNumTasks()));
    //txtNumDone->SetValue(std::to_string(model->getNumDoneTasks()));
}

ToDoListView::~ToDoListView() {
    if (model)
        model->removeObserver(this);
}
