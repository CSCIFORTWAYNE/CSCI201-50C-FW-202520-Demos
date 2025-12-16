#ifndef DRINKE_H
#define DRINKE_H
#include <stdexcept>
#include <string>

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

struct flavorException : public std::runtime_error
{
    flavorException(std::string msg);
};
struct duplicateFlavorException : public flavorException
{
    duplicateFlavorException(std::string msg);
};

#endif