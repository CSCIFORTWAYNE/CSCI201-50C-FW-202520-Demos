#include <iostream>
#include <limits>
#include "clock.h"

template <class Type>
Type inputType(std::string prompt, std::string err, bool (*valid)(Type, Type, Type), Type low = 0, Type high = 0);

template <class Type>
bool itemGT(Type item, Type low, Type = 0);
template <class Type>
bool itemInRange(Type item, Type low, Type high);
template <class Type>
bool isAorB(Type item, Type a, Type b);

void resetStream();

int main()
{
    TwelveHrClock a = inputType("Enter the clock data.", "That is not a valid clock", itemInRange, TwelveHrClock(10, 0, 0, partType::AM), TwelveHrClock(1, 0, 0, partType::PM));
    std::cout << a << std::endl;
    return 0;
}

bool numGTEQX(int num, int x, int)
{
    return num >= x;
}

bool isAorB(int num, int a, int b)
{
    return num == a || num == b;
}

template <class Type>
Type inputType(std::string prompt, std::string err, bool (*valid)(Type, Type, Type), Type low, Type high)
{
    Type item;
    std::cout << prompt;
    std::cin >> item;
    while (!std::cin || !valid(item, low, high))
    {
        if (!std::cin)
        {
            resetStream();
        }

        std::cout << err << std::endl;
        std::cout << prompt;
        std::cin >> item;
    }
    return item;
}

template <class Type>
bool itemInRange(Type item, Type low, Type high)
{
    return low <= item && high >= item;
}

void resetStream()
{
    std::cout << "You have entered non-numeric data! Please try again!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}