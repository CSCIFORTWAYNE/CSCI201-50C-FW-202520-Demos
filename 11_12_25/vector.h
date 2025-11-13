#ifndef VECTOR
#define VECTOR

class Vector
{
public:
    Vector(int);
    Vector(const Vector &);
    ~Vector();
    int size();
    int max_Size();
    void resize(int newSize);
    bool empty();
    void shrink_to_fit();
    int at(int);
    int *data();
    void assign(int, int);
    void push_back(int);
    void pop_back();
    void clear();

private:
    int *numbers;
    int numNums;
    int maxSize;
};

#endif