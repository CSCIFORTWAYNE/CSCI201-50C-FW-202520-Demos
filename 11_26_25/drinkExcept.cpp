#include "drinkExcept.h"

sizeException::sizeException(std::string msg) : runtime_error(msg + " is not a valid size.")
{
}

baseException::baseException(std::string msg) : runtime_error(msg + " is not a valid drink base.")
{
}
