#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "drink.h"

int main()
{
    std::string sizeStr;
    std::string baseStr;
    sizeType size;
    bool validSize = false;
    bool validBase = false;
    while (!validSize || !validBase)
    {
        try
        {
            if (!validSize)
            {
                std::cout << "Enter the drink size: ";
                getline(std::cin >> std::ws, sizeStr);
                validSize = true;
            }
            if (!validBase)
            {
                std::cout << "What kind of drink? ";
                getline(std::cin >> std::ws, baseStr);
                validBase = true;
            }

            drink newDrink(baseStr, "", sizeStr, "");
        }

        catch (int exception)
        {
            std::cout << "Exception caught" << std::endl;
        }
        catch (std::out_of_range e)
        {
            std::cout << e.what() << std::endl;
        }
        catch (baseException e)
        {
            std::cout << e.what() << std::endl;
            validBase = false;
        }
        catch (sizeException e)
        {
            std::cout << e.what() << std::endl;
            validSize = false;
        }
        }
    std::cout << "after try catch" << std::endl;
    return 0;
}