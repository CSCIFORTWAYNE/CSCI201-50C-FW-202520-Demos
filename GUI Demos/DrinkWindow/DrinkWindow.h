#ifndef _DrinkWindow_DrinkWindow_h
#define _DrinkWindow_DrinkWindow_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <DrinkWindow/DrinkWindow.lay>
#include <CtrlCore/lay.h>

class DrinkWindow : public WithDrinkWindowLayout<TopWindow> {
public:
	DrinkWindow();
};

#endif
