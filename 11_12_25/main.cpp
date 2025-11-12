#include <iostream>
#include <limits>
#include <cctype>
#include <string>

void resetStream();
int inputInt(std::string prompt, std::string err, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool numGT0(int num, int = 0, int = 0);
bool numInRange(int num, int low, int high);
bool numGTEQ0(int num, int = 0, int = 0);
bool numGTEQX(int num, int x, int = 0);

int main()
{
    numGT0(4);
    numGT0(4, 0, 1);
    int x = inputInt("Enter a number between 1 and 100: ", "Please enter a number between 1 and 100.", numInRange, 1, 100);
    int y = inputInt("Enter a number greater than 0.", "Please enter a number greater than 0.", numGT0);
    return 0;
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