#include <iostream>

class houseType
{
    int noBedrooms = 3;
    int noBathrooms;
    double sqFt;
    bool basement;

public:
    int getNoBedrooms();
};

int main()
{
    houseType myHouse;
    // myHouse.getNoBedrooms();
    //  myHouse.noBedrooms = 4;
    //  myHouse.noBathrooms = 3;
    //  myHouse.sqFt = 2000.3;
    //  myHouse.basement = true;
    //  std::cout << myHouse;

    return 0;
}

int getNoBedrooms()
{
    return 7;
}