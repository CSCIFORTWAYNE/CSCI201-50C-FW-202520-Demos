#include "DrinkWindow.h"

DrinkWindow::DrinkWindow()
{
	CtrlLayout(*this, "Window title");
}

GUI_APP_MAIN
{
	DrinkWindow().Run();
}
