#include <iostream>
#include <limits>
#include "clock.h"

timeType inputTimeType();
partType inputPartOfDay();
int inputHour(timeType);
int inputMinuteOrSecond(std::string);
void resetStream();

int main()
{
    clockType *clock = nullptr;
    int *p = nullptr;
    int x = 7;
    p = &x;
    std::cout << *p << std::endl;
    *p = 19;
    p = nullptr;
    std::cout << x << std::endl;

    timeType time = inputTimeType();
    int hour = inputHour(time);
    int min = inputMinuteOrSecond("minutes");
    int sec = inputMinuteOrSecond("seconds");
    partType partOfDay = partType::PM;
    if (time == TWELVE)
    {
        partOfDay = inputPartOfDay();
    }
    clock = new clockType(hour, min, sec, time, partOfDay);

    (*clock).printTime();
    clock->printTime();

    return 0;
}

timeType inputTimeType()
{
    timeType time;
    int timeInt;
    /*     std::cout << "Is the clock " << std::endl;
        std::cout << "1. Twelve Hour" << std::endl;
        std::cout << "2. Twenty-Four Hour" << std::endl; */
    std::cout << "Is the clock 12 hour or 24 hour? ";
    std::cin >> timeInt;
    while (!std::cin || (timeInt != 12 && timeInt != 24))
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please enter 12 or 24." << std::endl;
        std::cout << "Is the clock 12 hour or 24 hour? ";
        std::cin >> timeInt;
    }
    timeInt = (timeInt / 12) - 1;

    return formats[timeInt];
}

partType inputPartOfDay()
{
    int partInt = -1;
    std::cout << "Is it " << std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout << i + 1 << ". " << partToStr[i] << std::endl;
    }
    std::cin >> partInt;
    while (!std::cin || partInt < 1 || partInt > 2)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Is it " << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::cout << i + 1 << ". " << partToStr[i] << std::endl;
        }
        std::cin >> partInt;
    }

    return parts[partInt - 1];
}

int inputHour(timeType t)
{
    int hour;
    std::cout << "Enter the hour on the clock: ";
    std::cin >> hour;
    std::cout << std::endl;
    while (!std::cin || (t == TWELVE && hour < 1) || (t == TWELVE && hour > 12) || hour < 0 || hour > 23)
    {
        if (!std::cin)
        {
            resetStream();
        }
        if (t == TWELVE)
        {
            std::cout << "Please enter a number bewteen 1 and 12. " << std::endl;
        }
        else
        {
            std::cout << "Please enter a number bewteen 0 and 23. " << std::endl;
        }
        std::cout << "Enter the hour on the clock: ";
        std::cin >> hour;
        std::cout << std::endl;
    }

    return hour;
}

int inputMinuteOrSecond(std::string prompt)
{
    int mors;
    std::cout << "Enter the " << prompt << " on the clock: ";
    std::cin >> mors;
    std::cout << std::endl;
    while (!std::cin || mors < 0 || mors > 59)
    {
        if (!std::cin)
        {
            resetStream();
        }

        std::cout << "Please enter a number bewteen 0 and 59. " << std::endl;

        std::cout << "Enter the " << prompt << " on the clock: ";
        std::cin >> mors;
        std::cout << std::endl;
    }

    return mors;
}

void resetStream()
{
    std::cout << "You have entered non-numeric data! Please try again!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
