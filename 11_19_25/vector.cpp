#include "vector.h"

Vector::Vector(int maxSize)
{
    this->maxSize = maxSize;
    numbers = new int[maxSize];
    this->numNums = 0;
}

Vector::Vector(const Vector &vectorToCopy)
{

    this->numbers = nullptr;
    copyVector(vectorToCopy);
}

Vector::~Vector()
{
    delete[] this->numbers;
}

int Vector::size()
{
    return numNums;
}

int Vector::max_Size()
{
    return maxSize;
}

void Vector::resize(int newSize)
{
    if (newSize < maxSize)
    {
        return;
    }
    int *temp = numbers;
    numbers = new int[newSize];
    for (int i = 0; i < numNums; i++)
    {
        numbers[i] = temp[i];
    }
    delete[] temp;
    maxSize = newSize;
}

bool Vector::empty()
{
    return numNums == 0;
}

void Vector::shrink_to_fit()
{
    if (maxSize != numNums)
    {
        int *temp = numbers;
        numbers = new int[numNums];
        for (int i = 0; i < numNums; i++)
        {
            numbers[i] = temp[i];
        }
        maxSize = numNums;
        delete[] temp;
    }
}

int Vector::at(int position)
{
    return numbers[position];
}

int *Vector::data()
{
    return numbers;
}

void Vector::assign(int howMany, int value)
{
    this->clear();
    this->maxSize = howMany;
    numbers = new int[maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        numbers[i] = value;
    }
}

void Vector::push_back(int value)
{
    if (numNums == maxSize)
    {
        resize(maxSize + 1);
    }
    numbers[numNums] = value;
    numNums++;
}

void Vector::pop_back()
{
    numNums--;
}

void Vector::clear()
{
    numNums = 0;
    maxSize = 0;
    delete[] numbers;
}

const Vector &Vector::operator=(const Vector &otherVector)
{
    if (this != &otherVector)
    {
        copyVector(otherVector);
    }
}

void Vector::copyVector(const Vector &otherVector)
{
    if (this->numbers != nullptr)
    {
        delete[] this->numbers;
    }
    this->maxSize = otherVector.maxSize;
    this->numbers = new int[this->maxSize];
    this->numNums = otherVector.numNums;
    for (int i = 0; i < this->numNums; i++)
    {
        this->numbers[i] = otherVector.numbers[i];
    }
}