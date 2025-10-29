#include "clock.h"

void clockType::setTime(int h, int m, int s)
{
    if (h < 0 || h > 23)
    {
        h = 0;
    }

    hr = h;

    if (m < 0 || m > 59)
    {
        m = 0;
    }
    min = m;

    if (s < 0 || s > 59)
    {
        s = 0;
    }
    sec = s;
}
