#ifndef TODOLIST_VIEW_H
#define TODOLIST_VIEW_H

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/checkbox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class View
///////////////////////////////////////////////////////////////////////////////
class View : public wxFrame {
private:

protected:
    wxStaticText *nameNewList;
    wxTextCtrl *txtListName;
    wxButton *newListButton;
    wxStaticLine *m_staticline1;
    wxStaticText *descTask;
    wxTextCtrl *txtDesc;
    wxButton *newTaskButton;
    wxStaticText *dateTask;
    wxTextCtrl *txtDate;
    wxStaticText *timeTask;
    wxTextCtrl *txtTime;
    wxStaticText *priorityTask;
    wxTextCtrl *txtPriority;
    wxStaticText *doneTask;
    wxCheckBox *checkBoxDone;
    wxStaticLine *m_staticline2;
    wxStaticText *nameRemoveList;
    wxTextCtrl *txtRemoveName;
    wxButton *removeListButton;
    wxStaticLine *m_staticline3;
    wxStaticText *numLists;
    wxTextCtrl *txtNumLists;
    wxStaticText *numTasks;
    wxTextCtrl *txtNumTasks;
    wxStaticText *numDone;
    wxTextCtrl *txtNumDone;

    // Virtual event handlers, override them in your derived class
    virtual void onNewListClick(wxCommandEvent &event) { event.Skip(); }

    virtual void onNewTaskClick(wxCommandEvent &event) { event.Skip(); }

    virtual void onRemoveListClick(wxCommandEvent &event) { event.Skip(); }


public:

    View(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxEmptyString,
         const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(700, 500),
         long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

    ~View();

};


#endif //TODOLIST_VIEW_H
