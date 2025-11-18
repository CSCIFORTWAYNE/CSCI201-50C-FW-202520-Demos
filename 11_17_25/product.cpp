#include "product.h"

product::product(int pn, std::string desc, double p, int q)
{
    prodNum = pn;
    setDescription(desc);
    setPrice(p);
    setQuantity(q);
}

double product::getPrice() const
{
    return price;
}

std::string product::getDescription() const
{
    return description;
}

int product::getProdNum() const
{
    return prodNum;
}

int product::getQuantity() const
{
    return quantity;
}

void product::setPrice(double p)
{
    if (p <= 0)
    {
        p = 1;
    }
    price = p;
}

void product::setDescription(std::string desc)
{
    description = desc;
}

void product::setQuantity(int q)
{
    if (q < 0)
    {
        q = 0;
    }
    quantity = q;
}

std::string product::tostring() const
{
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    out << "Product: " << prodNum << " - " << description << ", $" << price << " QOH-" << quantity;
    return out.str();
}

std::string drink::flavToStr[NUM_FLAV] = {
    "Almond",
    "Apple",
    "Blueberry",
    "Butter Pecan",
    "Caramel",
    "French Vanilla",
    "Peach",
    "Peppermint",
    "Raspberry",
    "Strawberry",
    "Mocha"};

drink::flavType drink::flavs[NUM_FLAV] = {
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
    MOCHA};

drink::drink(bool c, bool h, sizeType s, flavType f[], int numF, int pn, std::string desc) : product(pn, desc, 2)
{
    this->numFlavor = -1;
    setCoffee(c);
    setHot(h);
    setSize(s);
    setFlavors(f, numF);
    calculatePrice();
}
drink::drink(bool c, bool h, sizeType s, flavType f[], int numF) : product(23, "drink", 2)
{
    this->numFlavor = -1;
    setCoffee(c);
    setHot(h);
    setSize(s);
    setFlavors(f, numF);
    calculatePrice();
}

bool drink::isCoffee() const
{
    return coffee;
}
bool drink::isHot() const
{
    return hot;
}
drink::sizeType drink::getSize() const
{
    return size;
}
std::string drink::getFlavors() const
{
    std::ostringstream out;
    if (numFlavor > 0)
    {
        out << flavToStr[static_cast<int>(flavors[0])];
        for (int i = 1; i < numFlavor; i++)
        {
            out << ", " << flavToStr[static_cast<int>(flavors[i])];
        }
    }
    return out.str();
}
void drink::setCoffee(bool c)
{
    coffee = c;
    calculatePrice();
}
void drink::setHot(bool h)
{
    hot = h;
    calculatePrice();
}
void drink::setSize(sizeType s)
{
    size = s;
    calculatePrice();
}
void drink::setFlavors(flavType f[], int numF)
{

    if (numF > NUM_FLAV)
    {
        numF = NUM_FLAV;
    }
    flavors = new flavType[numF];
    for (int i = 0; i < numF; i++)
    {
        flavors[i] = f[i];
    }
    numFlavor = numF;
    calculatePrice();
}
double drink::calculatePrice()
{
    if (numFlavor != -1)
    {
        switch (size)
        {
        case sizeType::SMALL:
            price = 2.00;
            break;
        case sizeType::MED:
            price = 3.00;
            break;
        case sizeType::LRG:
            price = 4.00;
            break;
        }
        if (coffee)
        {
            price += 2.00;
        }
        else
        {
            price += 1.00;
        }
        if (!hot)
        {
            price += 1.00;
        }
        price += .5 * numFlavor;
    }
    else
    {
        price = 0;
    }
    // product::setPrice(price);
    return price;
}

std::string drink::tostring() const
{
    std::ostringstream out;
    out << product::tostring();
    out << " Is Coffee? " << (coffee ? "Yes" : "No");
    out << " Is Hot? " << (hot ? "Yes" : "No");
    out << " Size: ";
    out << " Flavors: " << getFlavors() << " ";
    return out.str();
}
drink::drink(const drink &drinkToCopy) : product(drinkToCopy.prodNum, drinkToCopy.description, drinkToCopy.price, drinkToCopy.quantity)
{
    this->coffee = drinkToCopy.coffee;
    this->hot = drinkToCopy.hot;
    this->size = drinkToCopy.size;
    this->numFlavor = drinkToCopy.numFlavor;
    this->flavors = new flavType[numFlavor];
    for (int i = 0; i < numFlavor; i++)
    {
        this->flavors[i] = drinkToCopy.flavors[i];
    }
}
drink::~drink()
{
    delete[] flavors;
}
int iceCream::prodNum = 1;
iceCream::iceCream(flavType f, int s) : product(900 + prodNum++, "Ice Cream", 2)
{
    setFlavor(f);
    setScoopAmount(s);
    scoopPricing();
}

std::string iceCream::getFlavor() const
{
    return flavors[static_cast<int>(flavor)];
}

int iceCream::getScoopAmount() const
{
    return scoopAmount;
}

void iceCream::setFlavor(flavType f)
{
    flavor = f;
}

void iceCream::setScoopAmount(int s)
{
    if (s <= 0)
    {
        s = 1;
    }
    scoopAmount = s;
}

std::string iceCream::tostring() const
{
    std::ostringstream out;
    out << product::tostring() << std::endl;
    out << scoopAmount << " scoops of " << getFlavor();
    return out.str();
}

void iceCream::scoopPricing()
{
    switch (scoopAmount)
    {
    case 1:
        price = 3.0;
    case 2:
        price = 4.0;
    case 3:
        price = 5.0;
    default:
        price = scoopAmount * 1.65;
    }
}

std::string iceCream::flavors[24] = {
    "Vanilla",
    "Chocolate",
    "Strawberry",
    "Mint Chocolate Chip",
    "Cookie Dough",
    "Cookies And Cream",
    "Butter Pecan",
    "Rocky Road",
    "Chocolate Chip",
    "Moose Tracks",
    "Chocolate Fudge Brownie",
    "Pistachio",
    "Rum Raisin",
    "Neapolitan",
    "French Vanilla",
    "Peanut Butter Cup",
    "Black Raspberry",
    "Birthday Cake",
    "Caramel Swirl",
    "Maple Walnut",
    "Banana Split",
    "Tutti Frutti",
    "Orange Sherbet",
    "Coconut"

};
