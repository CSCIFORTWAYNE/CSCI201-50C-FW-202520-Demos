#ifndef _DrinkWindow_DrinkWindow_h
#define _DrinkWindow_DrinkWindow_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;
//try to add/demo
//slider
//progress bar
//column list
//tab
//color
//file selector //
//Edit Int Spin //
//splitter
//calendar ctrl


#define LAYOUTFILE <DrinkWindow/DrinkWindow.lay>
#include <CtrlCore/lay.h>
#include <AutoScroller/AutoScroller.h>
#include "drink.h"
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>

class DrinkWindow : public WithMainAppWindow<TopWindow> {
public:
	DrinkWindow();
	void checkPrice();
	void handleFlavor(int i);
	void saveOrder();
private:
	AutoScroller scroller;
	WithDrinkWindowLayout<ParentCtrl> scroller_view;
	Option flavor[NUM_FLAV];
	drink d;
	std::vector<drink> order;
	Button writeBtn;
	OptionTree optree;
};

#endif
