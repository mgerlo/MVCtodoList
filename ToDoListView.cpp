#include "ToDoListView.h"

ToDoListView::ToDoListView(wxWindow *parent, Model *model, Controller *controller)
        : View(parent), model(model), controller(controller) {
    model->addObserver(this);
}

void ToDoListView::onNewListClick(wxCommandEvent &event) {
    //controller->newList();
}

void ToDoListView::onNewTaskClick(wxCommandEvent &event) {
    // controller->newTask(); // da implementare in futuro
}

void ToDoListView::onRemoveListClick(wxCommandEvent &event) {
    controller->removeList();
}

void ToDoListView::update() {
    txtNumLists->SetValue(std::to_string(model->getLists().size()));
    //txtNumTasks->SetValue(std::to_string(model->getNumTasks()));
    //txtNumDone->SetValue(std::to_string(model->getNumDoneTasks()));
}

ToDoListView::~ToDoListView() {
    if (model)
        model->removeObserver(this);
}
