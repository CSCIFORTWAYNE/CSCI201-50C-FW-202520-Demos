#pragma once

#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <map>
#include "drinkExcept.h"

enum baseType
{
    COFFEE,
    TEA,
    CREAM
};
enum tempType
{
    HOT,
    ICE,
    BLEND
};
enum sizeType
{
    SMALL,
    MED,
    LARGE
};

enum flavType
{
    HAZELNUT,
    APPLE,
    BUTTERPECAN,
    BLUEBERRY,
    CARAMEL,
    PEACH,
    MOCHA,
    RASPBERRY,
    FRENCHVANILLA,
    STRAWBERRY,
    PEPPERMINT,
    MANGO

};
const int NUM_DAIRY = 6;
const int NUM_FLAV = 12;

const std::string dairyStr[] = {"None",
                                "Skim Milk",
                                "Whole Milk",
                                "Oat Milk",
                                "Cream",
                                "Almond Milk"};

class drink
{
public:
    drink(baseType = CREAM, tempType = HOT, sizeType = SMALL, std::string dairy = "None");
    drink(std::string base, std::string temp, std::string size, std::string dairy);
    std::string getBaseStr() const;
    std::string getTemperature() const;
    std::string getSize() const;
    std::string getDairy() const;
    std::string getFlavor() const;
    double getPrice() const;
    void setBase(baseType);
    void setBase(std::string);
    void setTemperature(tempType);
    void setTemperature(std::string);
    void setSize(sizeType);
    void setSize(std::string);
    void setDairy(std::string);
    void addFlavor(flavType);
    void addFlavor(std::string);
    void removeFlavor(flavType);
    void removeAllFlavor();
    friend std::ostream &operator<<(std::ostream &, const drink &);
    static std::map<baseType, std::string> baseToStr;
    static std::map<std::string, baseType> strToBase;
    static std::map<sizeType, std::string> sizeToStr;
    static std::map<std::string, sizeType> strToSize;
    static std::map<tempType, std::string> tempToStr;
    static std::map<std::string, tempType> strToTemp;
    static std::map<flavType, std::string> flavToStr;
    static std::map<std::string, flavType> strToFlav;

private:
    baseType base;
    tempType temperature;
    sizeType size;
    std::string dairy;
    std::set<flavType> flavors;
    std::string tostring() const;
};