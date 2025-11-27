#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <limits>
#include "drink.h"

void resetStream();
int inputInt(std::string prompt, std::string err);
drink *inputDrinkOrder();
void codeGradeLoopFix(std::string errLocation);
std::string inputDrinkSize();
std::string inputDrinkTemp();
std::string inputDrinkBase();
void addFlavorToDrink(drink &thedrink);

// M05 part b lab fill in setTemperature in drink.cpp
// fill in temperature code in inputDrinkOrder ~line 126

int main()
{
    std::string sizeStr;
    std::string baseStr;
    sizeType size;
    bool validSize = false;
    bool validBase = false;

    inputDrinkOrder();

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

int inputInt(std::string prompt, std::string err)
{

    int num;
    std::cout << prompt;
    std::cin >> num;
    if (!std::cin)
    {
        resetStream();
        throw std::runtime_error(err);
    }
    return num;
}

drink *inputDrinkOrder()
{
    drink *order;
    int numDrinks;
    try
    {
        numDrinks = inputInt("How many drinks? ", "That is not a valid number of drinks");
    }
    catch (std::runtime_error e)
    {
        std::cerr << e.what() << std::endl;
        codeGradeLoopFix("inputDrinkOrder, input num drinks");
        throw;
    }
    order = new drink[numDrinks];
    std::string sizeStr;
    std::string baseStr;
    std::string tempStr;
    bool size = false, temp = false, base = false;
    for (int i = 0; i < numDrinks; i++)
    {
        if (!size)
        {
            try
            {
                std::cout << "Enter the drink size: ";
                getline(std::cin >> std::ws, sizeStr);
                order[i].setSize(sizeStr);
                size = true;
            }
            catch (sizeException e)
            {
                std::cerr << e.what() << '\n';
                i--;
                continue;
            }
        }
        if (!temp)
        {
            // add code for temperature
        }
        if (!base)
        {
            try
            {
                std::cout << "What kind of drink? ";
                getline(std::cin >> std::ws, baseStr);
                order[i].setBase(baseStr);
                base = true;
            }
            catch (baseException b)
            {
                std::cout << b.what() << std::endl;
                i--;
                continue;
            }
        }
        addFlavorToDrink(order[i]);

        base = false;
        size = false;
        temp = false;
    }

    return order;
}

void codeGradeLoopFix(std::string errLocation)
{
    if (std::cin.eof())
    {
        std::cout << "There was a problem and there is no more input! @" + errLocation << std::endl;
        throw std::invalid_argument(errLocation);
    }
}

void resetStream()
{
    // std::cout << "You have entered non-numeric data! Please try again!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addFlavorToDrink(drink &thedrink)
{
    std::string flavStr;
    while (flavStr != "-1")
    {
        std::cout << "Please enter a flavor enter -1 to stop: ";
        getline(std::cin >> std::ws, flavStr);
        if (flavStr == "-1")
        {
            return;
        }
        try
        {
            thedrink.addFlavor(flavStr);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}