#include <iostream>

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

#include "ToDoListView.h"

class MyApp : public wxApp {
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    Model *model = new Model;
    Controller *controller = new Controller(model);
    ToDoListView *frame = new ToDoListView(nullptr, model, controller);
    //View *frame = new View(nullptr, wxID_ANY, "ToDo_List GUI");
    frame->Show(true);
    return true;
}


/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/
