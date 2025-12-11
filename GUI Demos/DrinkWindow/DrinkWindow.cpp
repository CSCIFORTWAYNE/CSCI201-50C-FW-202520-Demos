#include "DrinkWindow.h"


DrinkWindow::DrinkWindow()
{
	CtrlLayout(*this, "Drink Order Form");
	Sizeable().Zoomable();
	scroller.EnableScroll();
	
	Add(scroller.SizePos());
	CtrlLayout(scroller_view);
	scroller.AddPane(scroller_view);
	scroller_view.base = -1;
	scroller_view.temp = -1;
	scroller_view.size = -1;
	
	for(int i = 0; i < NUM_DAIRY; i++)
	{
		scroller_view.dairy.Add(dairyStr[i]);
	}
	
	int optionSize = 100;
	int rowDist = 20;
	int rowCount = 0;
	int i = 0;
	for(std::map<flavType, std::string>::iterator it = drink::flavToStr.begin(); it != drink::flavToStr.end(); ++it)
	{
		flavor[i].SetLabel(it->second.c_str());
		scroller_view.flavorOptions.Add(flavor[i].LeftPosZ(optionSize *(i%2), optionSize).TopPosZ(rowDist * rowCount));
		if(i%2 == 1)
		{
			rowCount++;
		}
		i++;
	}
	
	
}
