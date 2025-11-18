#ifndef CLOCK_H
#define CLOCK_H
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
enum class partType
{
    AM,
    PM
};

const partType parts[2] = {partType::AM, partType::PM};
const std::string partToStr[2] = {"AM", "PM"};
class clockType
{
public:
    // clockType();

    void getTime(int &, int &, int &) const;
    std::string printTime() const;
    bool validMin() const;
    bool validSec() const;
    void incrementSeconds();
    void incrementMinutes();
    void setMinute(int m);
    void setSecond(int s);
    virtual std::string toString() const;
    virtual void setTime(int, int, int);
    virtual bool validHr() const = 0;
    virtual void invalidHr() = 0;
    virtual void incrementHours() = 0;
    virtual void setHour(int hour) = 0;
    // bool equalTime(const clockType &) const ;

protected:
    int hr;
    int min;
    int sec;
};

class TwentyFourHrClock : public clockType
{
public:
    TwentyFourHrClock(int h = 0, int m = 0, int s = 0);
    // virtual void setTime(int, int, int);
    virtual bool validHr() const;
    virtual void invalidHr();
    virtual void incrementHours();
    virtual void setHour(int hour);
};

class TwelveHrClock : public clockType
{
public:
    TwelveHrClock(int h, int m, int s, partType part);
    // virtual void setTime(int, int, int);
    virtual bool validHr() const;
    virtual void invalidHr();
    virtual void incrementHours();
    virtual void setHour(int hour);
    void setPartOfDay(partType part);
    std::string getPartOfDay() const;
    partType getPartType() const;
    std::string toString() const;

private:
    partType partOfDay;
};

#endif