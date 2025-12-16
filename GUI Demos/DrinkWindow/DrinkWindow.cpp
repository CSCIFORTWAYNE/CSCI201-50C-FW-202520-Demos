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
	
	writeBtn.SetLabel("Complete Order");
	scroller_view.numDrinks.SetData(1);
	
	for(int i = 0; i < NUM_DAIRY; i++)
	{
		scroller_view.dairy.Add(dairyStr[i]);
	}
	scroller_view.dairy.GoBegin();
	
	int optionSize = 100;
	int rowDist = 20;
	int rowCount = 0;
	optree.SetRoot("All Flavors");
	optree.Add(0,"Gourmand");
	optree.Add(0,"Fruit");
	int i = 0;
	for(std::map<flavType, std::string>::iterator it = drink::flavToStr.begin(); it != drink::flavToStr.end(); ++it)
	{
		/*flavor[i].SetLabel(it->second.c_str());
		scroller_view.flavorOptions.Add(flavor[i].LeftPosZ(optionSize *(i%2), optionSize).TopPosZ(rowDist * rowCount));
		if(i%2 == 1)
		{
			rowCount++;
		}*/
		optree.Add(i%2 + 1, flavor[i],it->second.c_str());
		flavor[i] << [&, this, i]
		{
			handleFlavor(i);
		};
		i++;
	}
	scroller_view.flavorOptions.Add(optree.SizePos());
	optree.WhenOption = [&, this]
	{
	
			for(int i = 0; i < NUM_FLAV; i++)
			{
				handleFlavor(i);
			}
		
			
		
	};
	
	scroller_view.base << [&, this]
	{
		baseType b = drink::intToBase[(int)scroller_view.base];
		d.setBase(b);
		checkPrice();
	};
	
	scroller_view.temp << [&, this]
	{
		tempType t = drink::intToTemp[(int)scroller_view.temp];
		d.setTemperature(t);
		checkPrice();
	};
	scroller_view.size << [&,this]
	{
		sizeType s = drink::intToSize[scroller_view.size.GetData()];
		d.setSize(s);
		checkPrice();
	};
	
	scroller_view.dairy << [&, this]
	{
		d.setDairy(scroller_view.dairy.GetData().ToStd());
		checkPrice();
	};
	
	scroller_view.addBtn << [&, this]
	{
		if(scroller_view.size.GetData() == -1)
		{
			int def = ErrorYesNo("No size selected.\n Would you like to order a small?");
			if(!def)
			{
				return;
			}
		}
		if(scroller_view.base.GetData() == -1)
		{
			int def = ErrorYesNo("No base selected.\n Would you like to order a cream drink?");
			if(!def)
			{
				return;
			}
		}
		if(scroller_view.temp.GetData() == -1)
		{
			int def = ErrorYesNo("No temperature selected.\n Would you like to order a hot drink?");
			if(!def)
			{
				return;
			}
		}
		for(int i = 0; i < (int)scroller_view.numDrinks; i++)
		{
			order.push_back(d);
			std::ostringstream drinkStr;
			drinkStr << d << std::endl;
			scroller_view.drinkList.Append(drinkStr.str());
		}
		scroller_view.base = -1;
		scroller_view.temp = -1;
		scroller_view.size = -1;
		d.setBase(CREAM);
		d.setTemperature(HOT);
		d.setSize(SMALL);
		scroller_view.dairy.GoBegin();
		d.setDairy("None");
		d.removeAllFlavor();
		//for( int i = 0; i < NUM_FLAV; i++)
//		{
//			flavor[i] = 0;
//		}

		scroller_view.price.SetData("");
		scroller_view.writeBtnHolder.Add(writeBtn.HSizePosZ().VSizePosZ());
		optree.Set(0,0);
	};
	
	writeBtn << [&, this]
	{
		saveOrder();
	};
	
	
	
}

void DrinkWindow::checkPrice()
{
	if((int)scroller_view.base != -1 && (int)scroller_view.temp != -1
		&& (int)scroller_view.size != -1)
	{
		std::ostringstream priceStr;
		priceStr << std::setprecision(2) << std::fixed << std::showpoint;
		priceStr << "$" << d.getPrice();
		scroller_view.price.SetData(priceStr.str());
	}
}


void DrinkWindow::handleFlavor(int i)
{
	std::string flavStr = flavor[i].GetLabel().ToStd();
	std::transform(flavStr.begin(), flavStr.end(), flavStr.begin(),
		::tolower);
	if(flavor[i].Get())
	{
		
		d.addFlavor(drink::strToFlav[flavStr]);
	}
	else
	{
		d.removeFlavor(drink::strToFlav[flavStr]);
	}
	checkPrice();
}

void DrinkWindow::saveOrder()
{
	FileSel fs;
	String path = fs.GetActiveDir();
	fs.DefaultName("order");
	fs.DefaultExt("txt");
	fs.ExecuteSaveAs("order.txt");
	std::ofstream outFile(fs.Get().ToStd());
	outFile << std::setprecision(2) << std::fixed << std::showpoint;
	double total = 0;
	for(int i = 0; i < order.size(); i++)
	{
		outFile << order[i] << std::endl;
		total += order[i].getPrice();
	}
	outFile << "Total: $" << total;
	outFile.close();
	Close();
}



