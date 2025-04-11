#include "Encoi_moy.h"

#include <iostream>
#include <string>
#include <fstream>
#include "convert.h"
#include "Dictionary.h"
#include "file_miner.h"
#include "err_proc.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main() {

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Encoimoy::Encoi_moy form;
	Application::Run(% form);

}