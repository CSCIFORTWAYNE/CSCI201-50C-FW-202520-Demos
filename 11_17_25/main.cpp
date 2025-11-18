#include <iostream>
#include <algorithm>
#include "product.h"

bool inputCoffee();
bool inputHot();
drink::sizeType inputSize();
drink::flavType *inputFlavors(int &numFlavors);
bool validateFlavor(std::string flav);
drink::flavType flavorFromString(std::string flavor);
void resetStream();
void printProduct(product *p);

int main()
{
    product *p = new product(1, "product base class", 23.99);
    int numFlavors;
    drink::flavType *f = inputFlavors(numFlavors);
    bool coffee = inputCoffee();
    bool hot = inputHot();
    drink::sizeType size = inputSize();
    drink *d = new drink(coffee, hot, size, f, numFlavors);
    printProduct(p);
    printProduct(d);
    // std::cout << p.tostring() << std::endl;
    // std::cout << d.tostring() << std::endl;
    delete[] f;
    return 0;
}

int inputInt(std::string prompt, std::string err, bool (*valid)(int, int, int), int low, int high)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    while (!std::cin || !valid(num, low, high))
    {
        if (!std::cin)
        {
            resetStream();
        }

        std::cout << err << std::endl;
        std::cout << prompt;
        std::cin >> num;
    }
    return num;
}

bool numInRange(int num, int low, int high)
{
    return low <= num && high >= num; // low <= num <= high; bad don't do this
}

bool numGTEQ0(int num, int, int)
{
    return num >= 0;
}

bool numGTEQX(int num, int x, int)
{
    return num >= x;
}

bool isAorB(int num, int a, int b)
{
    return num == a || num == b;
}
bool numGT0(int num, int, int)
{
    return num > 0;
}

void resetStream()
{
    std::cout << "You have entered non-numeric data! Please try again!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool inputCoffee()
{
    // TODO: fill in with input to ask if coffee or not
    return true;
}

bool inputHot()
{
    // TODO: fill in with input to ask if hot or not
    return false;
}

drink::sizeType inputSize()
{
    char sizeChar;
    std::cout << "Would you like a (S)mall, (M)edium, or (L)arge drink? ";
    std::cin >> sizeChar;
    sizeChar = toupper(sizeChar);
    while (sizeChar != 'S' && sizeChar != 'M' && sizeChar != 'L')
    {
        std::cout << "Please enter S, M, or L." << std::endl;
        std::cout << "Would you like a (S)mall, (M)edium, or (L)arge drink? ";
        std::cin >> sizeChar;
        sizeChar = toupper(sizeChar);
    }
    drink::sizeType size = drink::sizeType::SMALL;
    switch (sizeChar)
    {
    case 'S':
        size = drink::sizeType::SMALL;
        break;
    case 'M':
        size = drink::sizeType::MED;
        break;
    case 'L':
        size = drink::sizeType::LRG;
        break;
    }
    return size;
}

drink::flavType *inputFlavors(int &numFlavors)
{
    numFlavors = 0;
    drink::flavType *flavors = new drink::flavType[numFlavors + 1];
    std::string inputFlavor;
    while (inputFlavor != "-1")
    {
        std::cout << "Enter a flavor for the drink, enter -1 to move on: ";
        std::getline(std::cin >> std::ws, inputFlavor);

        while (!validateFlavor(inputFlavor))
        {
            if (inputFlavor == "-1")
            {
                return flavors;
            }
            std::cout << inputFlavor << " is not a valid flavor." << std::endl;
            std::cout << "Valid flavors are: " << drink::flavToStr[0];
            for (int i = 1; i < drink::NUM_FLAV; i++)
            {
                std::cout << ", " << drink::flavToStr[i];
            }
            std::cout << std::endl;
            std::cout << "Enter a flavor for the drink, enter -1 to move on: ";
            std::getline(std::cin >> std::ws, inputFlavor);
        }
        flavors[numFlavors] = flavorFromString(inputFlavor);
        numFlavors++;
        drink::flavType *temp = flavors;
        flavors = new drink::flavType[numFlavors + 1];
        for (int i = 0; i < numFlavors; i++)
        {
            flavors[i] = temp[i];
        }
        delete[] temp;
    }

    return flavors;
}

bool validateFlavor(std::string flav)
{
    bool valid = false;
    std::transform(flav.begin(), flav.end(), flav.begin(), ::tolower);
    for (int i = 0; i < drink::NUM_FLAV; i++)
    {
        std::string copy = drink::flavToStr[i];
        std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
        if (copy == flav)
        {
            valid = true;
            break;
        }
    }
    return valid;
}

drink::flavType flavorFromString(std::string flavor)
{
    std::transform(flavor.begin(), flavor.end(), flavor.begin(), ::tolower);
    for (int i = 0; i < drink::NUM_FLAV; i++)
    {
        std::string copy = drink::flavToStr[i];
        std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
        if (copy == flavor)
        {
            return drink::flavs[i];
        }
    }
    return drink::MOCHA;
}

void printProduct(product *p)
{
    std::cout << p->tostring() << std::endl;
    delete p;
}
