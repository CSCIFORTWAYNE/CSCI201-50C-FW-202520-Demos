#include <iostream>
#include <cstdlib>
#include "clock.h"

clockType createClock();

int main()
{
    int list[10] = {1};
    int list2[10];
    // list2 = list;

    clockType c;
    c.setTime(5, 43, 22, TWELVE, partType::PM);

    int hour = 0;
    int minute = 0;
    int second = 0;

    c.getTime(hour, minute, second);
    std::cout << hour << ":" << minute << ":" << second << std::endl;

    clockType yourClock(20, 1, 34);
    yourClock.getTime(hour, minute, second);
    clockType newClock(12);
    clockType newClock2(12, 34);
    newClock = newClock2;
    for (int i = 0; i < 100; i++)
    {
        clockType a = createClock();
        std::cout << a.printTime() << std::endl;
    }

    return 0;
}

clockType createClock()
{
    static int noClocks = 0;
    int hour;
    int minute;
    int second;
    int format;
    format = rand() % 2;
    partType tod = partType::PM;
    if (!format)
    {
        hour = (rand() % 12) + 1;
        int time = rand() % 2;
        tod = parts[time];
    }
    else
    {
        hour = rand() % 24;
    }
    minute = rand() % 60;
    second = rand() % 60;

    clockType newClock(hour, minute, second, formats[format], tod);
    noClocks++;
    std::cout << noClocks << " clocks created in the program." << std::endl;

    return newClock;
}
