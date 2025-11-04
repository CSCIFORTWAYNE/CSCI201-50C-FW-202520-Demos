#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

class product
{
public:
    product(int pn, std::string desc, double p, int q = 1);
    double getPrice() const;
    std::string getDescription() const;
    int getProdNum() const;
    int getQuantity() const;
    void setPrice(double p);
    void setDescription(std::string desc);
    void setQuantity(int q);
    std::string tostring() const;

protected:
    double price;
    std::string description;
    int prodNum;
    int quantity;
};

class drink : public product
{
public:
    enum class sizeType
    {
        SMALL,
        MED,
        LRG
    };
    enum flavType
    {
        ALMOND,
        APPLE,
        BLUEBERRY,
        BUTTERPECAN,
        CARAMEL,
        FRENCHVANILLA,
        PEACH,
        PEPPERMINT,
        RASPBERRY,
        STRAWBERRY,
        MOCHA
    };
    const static int NUM_FLAV = 11;
    drink(bool c, bool h, sizeType s, flavType f[], int numF);
    drink(bool c, bool h, sizeType s, flavType f[], int numF, int pn, std::string desc);
    bool isCoffee() const;
    bool isHot() const;
    sizeType getSize() const;
    std::string getFlavors() const;
    void setCoffee(bool c);
    void setHot(bool h);
    void setSize(sizeType s);
    void setFlavors(flavType f[], int numF);
    double calculatePrice();
    std::string tostring() const;
    static std::string flavToStr[NUM_FLAV];

private:
    bool coffee;
    bool hot;
    sizeType size;
    flavType flavors[NUM_FLAV];
    int numFlavor;
};

class iceCream : public product
{
public:
    enum class flavType
    {
        VANILLAICECREAM,
        CHOCOLATEICECREAM,
        STRAWBERRY,
        MINT_CHOCOLATE_CHIP,
        COOKIE_DOUGH,
        COOKIES_AND_CREAM,
        BUTTER_PECAN,
        ROCKY_ROAD,
        CHOCOLATE_CHIP,
        MOOSE_TRACKS,
        CHOCOLATE_FUDGE_BROWNIE,
        PISTACHIO,
        RUM_RAISIN,
        NEAPOLITAN,
        FRENCH_VANILLA,
        PEANUT_BUTTER_CUP,
        BLACK_RASPBERRY,
        BIRTHDAY_CAKE,
        CARAMEL_SWIRL,
        MAPLE_WALNUT,
        BANANA_SPLIT,
        TUTTI_FRUTTI,
        ORANGE_SHERBET,
        COCONUTICECREAM

    };
    iceCream(flavType = flavType::VANILLAICECREAM, int = 1);
    std::string getFlavor() const;
    int getScoopAmount() const;
    void setFlavor(flavType);
    void setScoopAmount(int);
    std::string tostring() const;
    void scoopPricing();
    static std::string flavors[24];

private:
    flavType flavor;
    int scoopAmount;
    static int prodNum;
};

#endif
