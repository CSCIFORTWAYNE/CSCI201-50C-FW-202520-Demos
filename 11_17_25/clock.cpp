#include "clock.h"

#include "clock.h"

/* void clockType::setTime(int h, int m, int s, timeType f, partType timeOfDay)
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
} */

void clockType::getTime(int &h, int &m, int &s) const
{
    h = hr;
    m = min;
    s = sec;
}

/* std::string clockType::printTime() const
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
} */

/* clockType::clockType()
{
    hr = 0;
    min = 0;
    sec = 0;
} */

/* bool clockType::equalTime(const clockType &otherClock) const
{
    return hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec;
} */

bool clockType::validMin() const
{
    return min >= 0 && min <= 59;
}

bool clockType::validSec() const
{
    return sec >= 0 && sec <= 59;
}

void clockType::incrementSeconds()
{
    sec++;
    if (sec > 59)
    {
        sec = 0;
        incrementMinutes();
    }
}
void clockType::incrementMinutes()
{
    min++;
    if (min > 59)
    {
        min = 0;
        incrementHours();
    }
}
void clockType::setMinute(int m)
{
    min = m;
    if (!validMin())
    {
        min = 0;
    }
}
void clockType::setSecond(int s)
{
    sec = s;
    if (!validSec())
    {
        sec = 0;
    }
}
std::string clockType::toString() const
{
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
    return out.str();
}

TwentyFourHrClock::TwentyFourHrClock(int h, int m, int s)
{
    setTime(h, m, s);
}

/* void TwentyFourHrClock::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
} */

bool TwentyFourHrClock::validHr() const
{
    return hr >= 0 && hr <= 23;
}

void TwentyFourHrClock::invalidHr()
{
    std::cout << "Hours must be between 0 and 23." << std::endl;
    std::cout << "Defaulting to 0." << std::endl;
    hr = 0;
}

void TwentyFourHrClock::incrementHours()
{
    hr++;
    if (hr > 23)
    {
        hr = 0;
    }
}

void TwentyFourHrClock::setHour(int hour)
{
    hr = hour;
    if (!validHr())
    {
        invalidHr();
    }
}

TwelveHrClock::TwelveHrClock(int h, int m, int s, partType part)
{
    setTime(h, m, s);
    setPartOfDay(part);
}

void clockType::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

bool TwelveHrClock::validHr() const
{
    return hr >= 1 && hr <= 12;
}

void TwelveHrClock::invalidHr()
{
    std::cout << "Hours must be between 1 and 12." << std::endl;
    std::cout << "Defaulting to 12." << std::endl;
    hr = 12;
}

void TwelveHrClock::incrementHours()
{
    hr++;
    if (hr == 12)
    {

        if (partOfDay == partType::AM)
        {
            partOfDay = partType::PM;
        }
        else
        {
            partOfDay = partType::AM;
        }
    }
    if (hr > 12)
    {
        hr = 1;
    }
}

void TwelveHrClock::setHour(int hour)
{
    hr = hour;
    if (!validHr())
    {
        invalidHr();
    }
}

void TwelveHrClock::setPartOfDay(partType part)
{
    partOfDay = part;
}

std::string TwelveHrClock::getPartOfDay() const
{
    return partToStr[static_cast<int>(partOfDay)];
}

partType TwelveHrClock::getPartType() const
{
    return partOfDay;
}

std::string TwelveHrClock::toString() const
{
    std::string output = clockType::toString();
    output += " " + getPartOfDay();
    return output;
}
