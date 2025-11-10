#include <iostream>
#include "clock.h"

int main()
{
    int *p = nullptr;
    int x = 7;
    p = &x;
    std::cout << *p << std::endl;
    *p = 19;
    p = nullptr;
    std::cout << x << std::endl;
    clockType *clock = nullptr;
    (*clock).printTime();
    clock->printTime();

    return 0;
}