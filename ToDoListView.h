#ifndef TODOLIST_TODOLISTVIEW_H
#define TODOLIST_TODOLISTVIEW_H

#include "View.h"
#include "Controller.h"
#include "Model.h"
#include "Observer.h"

class ToDoListView : public View, public Observer {
private:
    Model *model;
    Controller *controller;

public:
    ToDoListView(wxWindow *parent, Model *model, Controller *controller);

    // Event handler override
    void onNewListClick(wxCommandEvent &event) override;

    void onNewTaskClick(wxCommandEvent &event) override;

    void onRemoveListClick(wxCommandEvent &event) override;

    // Observer
    void update() override;
};

#endif //TODOLIST_TODOLISTVIEW_H
