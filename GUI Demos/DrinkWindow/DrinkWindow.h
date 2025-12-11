#ifndef _DrinkWindow_DrinkWindow_h
#define _DrinkWindow_DrinkWindow_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

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
