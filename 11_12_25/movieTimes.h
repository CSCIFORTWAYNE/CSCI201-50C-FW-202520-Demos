#ifndef MOVIE_H
#define MOVIE_H
#include "clock.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

class MovieTimes
{
public:
    MovieTimes(std::string title, int runtime, std::string rating);
    MovieTimes(const MovieTimes &);
    void enterTimes();
    std::string tostring() const;
    std::string getTitle();
    int getRuntime();
    std::string getRating();
    void addTime(clockType timeAdd);
    ~MovieTimes();

private:
    std::string title;
    int runtime;
    std::string rating;
    clockType **showTimes;
    int numTimes;
    void copyMovie(const MovieTimes &);
};

void resetStream();
int inputInt(std::string prompt, std::string err, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool numGT0(int num, int = 0, int = 0);
bool numInRange(int num, int low, int high);
bool numGTEQ0(int num, int = 0, int = 0);
bool numGTEQX(int num, int x, int = 0);
bool isAorB(int num, int a, int b);
clockType *makeClock();
partType inputPartOfDay();
timeType inputTimeType();

#endif