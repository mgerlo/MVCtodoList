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
    auto *model = new Model;
    auto *controller = new Controller(model);
    auto *frame = new ToDoListView(nullptr, model, controller);
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
