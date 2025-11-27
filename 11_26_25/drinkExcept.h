#ifndef DRINKE_H
#define DRINKE_H
#include <stdexcept>

class sizeException : public std::runtime_error
{
public:
    sizeException(std::string msg);
};
class baseException : public std::runtime_error
{
public:
    baseException(std::string msg);
};

#endif