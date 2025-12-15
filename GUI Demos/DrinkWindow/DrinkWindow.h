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
//file selector
//Edit Int Spin
//splittter
//calendar ctrl


#define LAYOUTFILE <DrinkWindow/DrinkWindow.lay>
#include <CtrlCore/lay.h>
#include <AutoScroller/AutoScroller.h>
#include "drink.h"

class DrinkWindow : public WithMainAppWindow<TopWindow> {
public:
	DrinkWindow();
private:
	AutoScroller scroller;
	WithDrinkWindowLayout<ParentCtrl> scroller_view;
	Option flavor[NUM_FLAV];
};

#endif
