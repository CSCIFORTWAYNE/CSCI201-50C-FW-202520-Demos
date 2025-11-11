#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype> //has toupper and tolower
#include "clock.h"

timeType inputTimeType();
partType inputPartOfDay();
int inputHour(timeType);
int inputMinuteOrSecond(std::string);
void resetStream();

// lecture activity M03A pick a class
// create a main showing a dynamic object
// and dynamic array using that class
// submit the code in a cpp or txt file

int main()
{
    clockType **clockList;
    char more = 'Y';
    clockList = new clockType *[1];
    int clockSize = 0;
    while (more == 'Y')
    {
        timeType time = inputTimeType();
        int hour = inputHour(time);
        int min = inputMinuteOrSecond("minutes");
        int sec = inputMinuteOrSecond("seconds");
        partType partOfDay = partType::PM;
        if (time == TWELVE)
        {
            partOfDay = inputPartOfDay();
        }
        clockList[clockSize++] = new clockType(hour, min, sec, time, partOfDay);
        std::cout << "Do you want another clock? ";
        std::cin >> more;
        more = toupper(more);
        while (more != 'Y' && more != 'N')
        {
            std::cout << "Please enter Y or N." << std::endl;
            std::cout << "Do you want another clock? ";
            std::cin >> more;
            more = toupper(more);
        }
        if (more == 'Y')
        {
            clockType **temp = clockList;
            clockList = new clockType *[clockSize + 1];
            for (int i = 0; i < clockSize; i++)
            {
                clockList[i] = temp[i];
            }
            delete[] temp;
        }
    }
    for (int i = 0; i < clockSize; i++)
    {
        std::cout << clockList[i]->printTime() << std::endl;
        delete clockList[i];
    }
    delete[] clockList;

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

/* old main
// clockType *clock = new clockType[10];
   clockType **clockList = nullptr;
   clockType *cList[10];

   int *p = nullptr;
   int x = 7;
   p = &x;
   std::cout << *p << std::endl;
   *p = 19;
   p = nullptr;
   // p = new int;
   std::cout << x << std::endl;
   std::cout << "How many numbers and clocks? ";
   std::cin >> x;
   // input validation loop

   int *list = new int[x];
   p = list;
   for (int i = 0; i < x; i++, p++)
   {
       list[i] = rand() % 100 + 1;
   }
   // p = &list[x];
   //  p = p + 1;
   std::cout << *p << std::endl;
   // std::cout << list[1] << std::endl;
   std::cout << p - list << std::endl;
   // std::cout << p[-1] << std::endl;
   // std::cout << list[3] << std::endl;
   clockList = new clockType *[x];
   for (int i = 0; i < x; i++)
   {
       timeType time = inputTimeType();
       int hour = inputHour(time);
       int min = inputMinuteOrSecond("minutes");
       int sec = inputMinuteOrSecond("seconds");
       partType partOfDay = partType::PM;
       if (time == TWELVE)
       {
           partOfDay = inputPartOfDay();
       }
       clockList[i] = new clockType(hour, min, sec, time, partOfDay);

       //(*clock).printTime();
       // clock->printTime();
   }
   for (int i = 0; i < x; i++)
   {
       std::cout << clockList[i]->printTime() << std::endl;
   }

   // delete p;
   // delete clock;
   delete[] list;
*/
