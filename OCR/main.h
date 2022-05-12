#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class MainApp : public wxApp
{
	virtual bool OnInit();
};
class MainWindow : public wxFrame
{
public:
	MainWindow();
	~MainWindow();
private:
	void onSave(wxCommandEvent& event);
	void onExit(wxCommandEvent& event);
	void onAbout(wxCommandEvent& event);
	enum {
		ID_SAVE = 1
	};
};