#include <iostream>
#include <algorithm>
#include <limits>
#include "vector.h"
#include "clock.h"
#include "movieTimes.h"

/* int inputInt(std::string prompt, std::string err, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool numGT0(int num, int = 0, int = 0);
bool numInRange(int num, int low, int high);
bool numGTEQ0(int num, int = 0, int = 0);
bool numGTEQX(int num, int x, int = 0);
bool isAorB(int num, int a, int b);

partType inputPartOfDay();
void clockTick(clockType &clockToTick);
void resetStream(); */

// M04 part b lab add > >= < <= to the TwentyFourHrClock class

int main()
{

    int x = 7;
    int y = ++x;
    const Vector list(10);
    y = list[9];
    clockType *c = makeClock();
    // clockType *c2 = makeClock();
    /* std::cout << c->toString() << std::endl;
    std::cout << c2->toString() << std::endl;
    clockTick(*c);
    clockTick(*c2);
    std::cout << c->toString() << std::endl;
    std::cout << c2->toString() << std::endl; */
    //  std::cout << p.tostring() << std::endl;
    //  std::cout << d.tostring() << std::endl;
    // std::cout << typeid(c).name() << std::endl;
    TwentyFourHrClock c24(12, 59, 59);
    TwentyFourHrClock anotherClock(11, 59, 59);
    std::cout << c24 << std::endl;
    const clockType *temp = &(c24++);
    delete temp;

    if (c24 == anotherClock)
    {
        std::cout << "Same clock" << std::endl;
    }
    else
    {
        std::cout << "different clock" << std::endl;
    }

    if (typeid(*c) == typeid(TwelveHrClock))
        if (c24 == *(static_cast<TwelveHrClock *>(c)))
        {
            std::cout << "clocks are the same" << std::endl;
        }

    return 0;
}

/* int inputInt(std::string prompt, std::string err, bool (*valid)(int, int, int), int low, int high)
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

partType inputPartOfDay()
{
    int partInt = -1;
    std::ostringstream prompt;
    prompt << "Is it " << std::endl;
    for (int i = 0; i < 2; i++)
    {
        prompt << i + 1 << ". " << partToStr[i] << std::endl;
    }
    partInt = inputInt(prompt.str(), "Please enter 1 or 2.", isAorB, 1, 2);

    return parts[partInt - 1];
}
 */
void clockTick(clockType &clockToTick)
{
    clockToTick.incrementHours();
    std::cout << clockToTick.toString() << std::endl;
}
