#include <iostream>

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

#include "View.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    View *frame = new View(nullptr, wxID_ANY, "ToDo_List GUI");
    frame->Show(true);
    return true;
}


/*
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/
