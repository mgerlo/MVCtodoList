#include "View.h"

View::View(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style)
        : wxFrame(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *bSizer1;
    bSizer1 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *bSizer2;
    bSizer2 = new wxBoxSizer(wxHORIZONTAL);

    nameNewList = new wxStaticText(this, wxID_ANY, _("Nome Lista :"), wxDefaultPosition, wxDefaultSize, 0);
    nameNewList->Wrap(-1);
    bSizer2->Add(nameNewList, 0, wxALL, 5);

    txtListName = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(txtListName, 0, wxALL, 5);

    newListButton = new wxButton(this, wxID_ANY, _("New List"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(newListButton, 0, wxALL, 5);


    bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

    m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    bSizer1->Add(m_staticline1, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer *bSizer3;
    bSizer3 = new wxBoxSizer(wxHORIZONTAL);

    descTask = new wxStaticText(this, wxID_ANY, _("Descrizione :"), wxDefaultPosition, wxDefaultSize, 0);
    descTask->Wrap(-1);
    bSizer3->Add(descTask, 0, wxALL, 5);

    txtDesc = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer3->Add(txtDesc, 0, wxALL, 5);

    newTaskButton = new wxButton(this, wxID_ANY, _("New Task"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer3->Add(newTaskButton, 0, wxALL, 5);


    bSizer1->Add(bSizer3, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer4;
    bSizer4 = new wxBoxSizer(wxHORIZONTAL);

    dateTask = new wxStaticText(this, wxID_ANY, _("Data (DD-MM-YYYY) :"), wxDefaultPosition, wxDefaultSize, 0);
    dateTask->Wrap(-1);
    bSizer4->Add(dateTask, 0, wxALL, 5);

    txtDate = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(txtDate, 0, wxALL, 5);


    bSizer1->Add(bSizer4, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer5;
    bSizer5 = new wxBoxSizer(wxHORIZONTAL);

    timeTask = new wxStaticText(this, wxID_ANY, _("Orario (HH:MM) :"), wxDefaultPosition, wxDefaultSize, 0);
    timeTask->Wrap(-1);
    bSizer5->Add(timeTask, 0, wxALL, 5);

    txtTime = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer5->Add(txtTime, 0, wxALL, 5);


    bSizer1->Add(bSizer5, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer6;
    bSizer6 = new wxBoxSizer(wxHORIZONTAL);

    priorityTask = new wxStaticText(this, wxID_ANY, _("Priorità :"), wxDefaultPosition, wxDefaultSize, 0);
    priorityTask->Wrap(-1);
    bSizer6->Add(priorityTask, 0, wxALL, 5);

    txtPriority = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer6->Add(txtPriority, 0, wxALL, 5);


    bSizer1->Add(bSizer6, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer7;
    bSizer7 = new wxBoxSizer(wxHORIZONTAL);

    doneTask = new wxStaticText(this, wxID_ANY, _("Completato :"), wxDefaultPosition, wxDefaultSize, 0);
    doneTask->Wrap(-1);
    bSizer7->Add(doneTask, 0, wxALL, 5);

    checkBoxDone = new wxCheckBox(this, wxID_ANY, _("Check Me!"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer7->Add(checkBoxDone, 0, wxALL, 5);


    bSizer1->Add(bSizer7, 1, wxEXPAND, 5);

    m_staticline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    bSizer1->Add(m_staticline2, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer *bSizer8;
    bSizer8 = new wxBoxSizer(wxHORIZONTAL);

    nameRemoveList = new wxStaticText(this, wxID_ANY, _("Nome Lista :"), wxDefaultPosition, wxDefaultSize, 0);
    nameRemoveList->Wrap(-1);
    bSizer8->Add(nameRemoveList, 0, wxALL, 5);

    txtRemoveName = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer8->Add(txtRemoveName, 0, wxALL, 5);

    removeListButton = new wxButton(this, wxID_ANY, _("Remove List"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer8->Add(removeListButton, 0, wxALL, 5);


    bSizer1->Add(bSizer8, 1, wxEXPAND, 5);

    m_staticline3 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    bSizer1->Add(m_staticline3, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer *bSizer9;
    bSizer9 = new wxBoxSizer(wxHORIZONTAL);

    numLists = new wxStaticText(this, wxID_ANY, _("Numero Liste :"), wxDefaultPosition, wxDefaultSize, 0);
    numLists->Wrap(-1);
    bSizer9->Add(numLists, 0, wxALL, 5);

    txtNumLists = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer9->Add(txtNumLists, 0, wxALL, 5);


    bSizer1->Add(bSizer9, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer10;
    bSizer10 = new wxBoxSizer(wxHORIZONTAL);

    numTasks = new wxStaticText(this, wxID_ANY, _("Numero Tasks :"), wxDefaultPosition, wxDefaultSize, 0);
    numTasks->Wrap(-1);
    bSizer10->Add(numTasks, 0, wxALL, 5);

    txtNumTasks = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer10->Add(txtNumTasks, 0, wxALL, 5);


    bSizer1->Add(bSizer10, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer11;
    bSizer11 = new wxBoxSizer(wxHORIZONTAL);

    numDone = new wxStaticText(this, wxID_ANY, _("Numero Completati :"), wxDefaultPosition, wxDefaultSize, 0);
    numDone->Wrap(-1);
    bSizer11->Add(numDone, 0, wxALL, 5);

    txtNumDone = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer11->Add(txtNumDone, 0, wxALL, 5);


    bSizer1->Add(bSizer11, 1, wxEXPAND, 5);


    this->SetSizer(bSizer1);
    this->Layout();

    this->Centre(wxBOTH);

    // Connect Events
    newListButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::onNewListClick), NULL, this);
    newTaskButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::onNewTaskClick), NULL, this);
    removeListButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(View::onRemoveListClick), NULL, this);
}

View::~View() {
}
