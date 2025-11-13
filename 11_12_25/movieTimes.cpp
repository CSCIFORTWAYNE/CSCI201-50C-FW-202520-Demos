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

MovieTimes::MovieTimes(const MovieTimes &moveToCopy)
{
    this->showTimes = nullptr;
    this->numTimes = 0;
    copyMovie(moveToCopy);
}

void MovieTimes::enterTimes()
{
    if (this->numTimes > 0)
    {
        for (int i = 0; i < this->numTimes; i++)
        {
            delete this->showTimes[i];
        }
        delete[] this->showTimes;
    }
    this->numTimes = inputInt("Enter the number of showtimes: ", "Please enter a number greater than 0.", numGT0);
    this->showTimes = new clockType *[this->numTimes];
    for (int i = 0; i < numTimes; i++)
    {
        std::cout << "Filling in clock for showtime #" << i + 1 << std::endl;
        clockType *c = makeClock();
        this->showTimes[i] = c;
    }
}

std::string MovieTimes::tostring() const
{
    std::ostringstream out;
    out << std::left;
    out << "| " << std::setw(40) << this->title << " | " << std::setw(5) << this->rating << " | " << std::setw(3) << this->runtime << " mins | ";
    for (int i = 0; i < numTimes; i++)
    {
        out << showTimes[i]->printTime() << " ";
    }

    return out.str();
}

std::string MovieTimes::getTitle()
{
    return title;
}

int MovieTimes::getRuntime()
{
    return runtime;
}

std::string MovieTimes::getRating()
{
    return rating;
}

void MovieTimes::addTime(clockType timeAdd)
{
    numTimes++;
    clockType **temp = showTimes;
    showTimes = new clockType *[numTimes];
    for (int i = 0; i < numTimes - 1; i++)
    {
        showTimes[i] = temp[i];
    }
    showTimes[numTimes - 1] = new clockType(timeAdd);
    delete[] temp;
}

MovieTimes::~MovieTimes()
{
    for (int i = 0; i < numTimes; i++)
    {
        delete showTimes[i];
    }
    delete[] showTimes;
}

void MovieTimes::copyMovie(const MovieTimes &movieToCopy)
{
    this->title = movieToCopy.title;
    this->rating = movieToCopy.rating;
    this->runtime = movieToCopy.runtime;
    if (this->numTimes > 0)
    {
        for (int i = 0; i < this->numTimes; i++)
        {
            delete this->showTimes[i];
        }
        delete[] showTimes;
    }
    // this->times = otherMovie.times; don't do this shallow copy
    this->numTimes = movieToCopy.numTimes;
    this->showTimes = new clockType *[this->numTimes];
    for (int i = 0; i < this->numTimes; i++)
    {
        // this->showTimes[i] = movieToCopy.showTimes[i]; shallow copy
        this->showTimes[i] = new clockType(*movieToCopy.showTimes[i]);
    }
}

int inputInt(std::string prompt, std::string err, bool (*valid)(int, int, int), int low, int high)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    while (!std::cin || !valid(num, low, high))
    {
        if (!std::cin)
        {
            resetStream();
        }

        std::cout << err << std::endl;
        std::cout << prompt;
        std::cin >> num;
    }
    return num;
}

bool numInRange(int num, int low, int high)
{
    return low <= num && high >= num; // low <= num <= high; bad don't do this
}

bool numGTEQ0(int num, int, int)
{
    return num >= 0;
}

bool numGTEQX(int num, int x, int)
{
    return num >= x;
}

bool isAorB(int num, int a, int b)
{
    return num == a || num == b;
}

clockType *makeClock()
{
    clockType *clockPtr = nullptr;
    timeType time = inputTimeType();
    std::string hourPrompt = "Enter the clock's hour: ";
    int hour;
    int min;
    int sec;
    if (time == TWELVE)
    {
        hour = inputInt(hourPrompt, "The hour must be between 1 and 12.", numInRange, 1, 12);
    }
    else
    {
        hour = inputInt(hourPrompt, "The hour must be between 0 and 23.", numInRange, 0, 23);
    }
    min = inputInt("Enter the clock's minutes: ", "The minute must be between 0 and 59", numInRange, 0, 59);
    sec = inputInt("Enter the clock's seconds: ", "The second must be between 0 and 59", numInRange, 0, 59);
    partType part = partType::PM;
    if (time == TWELVE)
    {
        part = inputPartOfDay();
    }
    // return clockType(hour, min, sec, time, part);
    clockPtr = new clockType(hour, min, sec, time, part);
    return clockPtr;
}

bool numGT0(int num, int, int)
{
    return num > 0;
}

void resetStream()
{
    std::cout << "You have entered non-numeric data! Please try again!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

timeType inputTimeType()
{
    timeType time;
    int timeInt = inputInt("Is the clock 12 hour or 24 hour? ", "Please enter 12 or 24.", isAorB, 12, 24);
    timeInt = (timeInt / 12) - 1;

    return formats[timeInt];
}

partType inputPartOfDay()
{
    int partInt = -1;
    std::ostringstream prompt;
    prompt << "Is it " << std::endl;
    for (int i = 0; i < 2; i++)
    {
        prompt << i + 1 << ". " << partToStr[i] << std::endl;
    }
    partInt = inputInt(prompt.str(), "Please enter 1 or 2.", isAorB, 1, 2);

    return parts[partInt - 1];
}
