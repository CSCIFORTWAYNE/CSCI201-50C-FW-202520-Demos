#include "clock.h"

void clockType::setTime(int h, int m, int s, timeType f, partType timeOfDay)
{
    format = f;
    part = timeOfDay;
    if (!validHour(h))
    {
        h = 12;
    }

    hr = h;

    if (!validMinOrSec(m))
    {
        m = 0;
    }
    min = m;

    if (!validMinOrSec(s))
    {
        s = 0;
    }
    sec = s;
}

void clockType::getTime(int &h, int &m, int &s) const
{
    h = hr;
    m = min;
    s = sec;
}

std::string clockType::printTime() const
{
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
    if (format == TWELVE)
    {
        int index;
        for (int i = 0; i < 2; i++)
        {
            if (part == parts[i])
            {
                index = i;
                break;
            }
        }
        out << " " << partToStr[index];
    }

    return out.str();
    // std::string output;
    // output += std::to_string(hr) + ":" + std::to_string(min);
}

/* clockType::clockType()
{
    hr = 0;
    min = 0;
    sec = 0;
} */

clockType::clockType(int hour, int minute, int second, timeType f, partType timeOfDay)
{
    setTime(hour, minute, second, f, timeOfDay);
}

bool clockType::equalTime(const clockType &otherClock) const
{
    return hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec;
}

bool clockType::validHour(int h)
{
    if (format == TWELVE)
    {
        return h > 0 && h <= 12;
    }
    else
    {
        return h >= 0 && h <= 23;
    }
    return false;
}

bool clockType::validMinOrSec(int num)
{

    return num >= 0 && num <= 59;
}
