#include "movieTimes.h"
MovieTimes::MovieTimes(std::string title, int runtime, std::string rating)
{
    this->title = title;
    if (runtime <= 0)
    {
        runtime = 1;
    }
    this->runtime = runtime;
    this->rating = rating;
    this->showTimes = nullptr;
    this->numTimes = 0;
}