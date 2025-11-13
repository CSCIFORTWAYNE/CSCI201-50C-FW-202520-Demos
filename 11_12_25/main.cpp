#include <iostream>
#include <limits>
#include <cctype>
#include <string>
#include "movieTimes.h"

// m03 part b lab use makeclock to make a clock to add a time to one of the movies.
// clean up memory

int main()
{
    numGT0(4);
    numGT0(4, 0, 1);
    // int x = inputInt("Enter a number between 1 and 100: ", "Please enter a number between 1 and 100.", numInRange, 1, 100);
    // int y = inputInt("Enter a number greater than 0.", "Please enter a number greater than 0.", numGT0);
    MovieTimes predator("Predator: Badlands", 107, "PG-13");
    predator.enterTimes();
    MovieTimes regrettingYou("Regretting You", 117, "PG-13");
    regrettingYou.enterTimes();
    MovieTimes sarahsOil("Sarah's Oil", 103, "PG");
    sarahsOil.enterTimes();
    {
        MovieTimes temp = sarahsOil;
    }
    std::cout << predator.tostring() << std::endl;
    std::cout << regrettingYou.tostring() << std::endl;
    std::cout << sarahsOil.tostring() << std::endl;

    clockType newClock(10);
    predator.addTime(newClock);
    std::cout << predator.tostring() << std::endl;
    return 0;
}
