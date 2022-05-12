#include "main.h"
#include "Logger.h"
wxIMPLEMENT_APP(MainApp);
bool MainApp::OnInit() {
	Logger::log("Application Started");
	MainWindow* window = new MainWindow();
	Logger::log("Window Created", Logger::LOGGING_LEVEL::LOG_DEBUG);
	window->Show(true);
	Logger::log("Window Displayed", Logger::LOGGING_LEVEL::LOG_DEBUG);
	return true;
}
void MainWindow::onSave(wxCommandEvent& event)
{
	Logger::log("Saved");
}
void MainWindow::onExit(wxCommandEvent& event)
{
	Logger::log("Closing Application");
	Close(true);
}
void MainWindow::onAbout(wxCommandEvent& event)
{
	wxMessageBox("", "About", wxCLOSE);
}
MainWindow::MainWindow() : wxFrame(NULL, wxID_ANY, "Test") {
	
	wxMenu* menuFile = new wxMenu;
	menuFile->Append(ID_SAVE, "&Save\tCtrl-S", "Save the interpreted text to a .txt file");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu* menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");

	SetMenuBar(menuBar);

	CreateStatusBar();
	SetStatusText("Welcome!");
	Bind(wxEVT_MENU, &MainWindow::onSave, this, ID_SAVE);
	Bind(wxEVT_MENU, &MainWindow::onAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MainWindow::onExit, this, wxID_EXIT);
}

MainWindow::~MainWindow()
{
	Logger::log("Closing Window");
	Logger::endFile();
}
