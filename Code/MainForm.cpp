#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	AppDomain::CurrentDomain->SetData("DataDirectory", Application::StartupPath);

	Kursova::MainForm form;
	Application::Run(% form);

	return 0;
}