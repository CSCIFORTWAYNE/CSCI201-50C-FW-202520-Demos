#ifndef MOVIE_H
#define MOVIE_H
#include "clock.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

class MovieTimes
{
public:
    MovieTimes(std::string title, int runtime, std::string rating);
    void enterTimes();
    std::string tostring() const;
    std::string getTitle();
    int getRuntime();
    std::string getRating();
    void addTime(clockType timeAdd);

private:
    std::string title;
    int runtime;
    std::string rating;
    clockType **showTimes;
    int numTimes;
};

#endif