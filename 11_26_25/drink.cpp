#include "drink.h"

std::map<baseType, std::string> drink::baseToStr = {{COFFEE, "Coffee"},
                                                    {TEA, "Tea"},
                                                    {CREAM, "Cream"}};
std::map<std::string, baseType> drink::strToBase = {{"COFFEE", COFFEE},
                                                    {"TEA", TEA},
                                                    {"CREAM", CREAM}};

std::map<flavType, std::string> drink::flavToStr = {{HAZELNUT, "Hazelnut"},
                                                    {APPLE, "Apple"},
                                                    {BUTTERPECAN, "Butter Pecan"},
                                                    {BLUEBERRY, "Blueberry"},
                                                    {CARAMEL, "Caramel"},
                                                    {PEACH, "Peach"},
                                                    {MOCHA, "Mocha"},
                                                    {RASPBERRY, "Raspberry"},
                                                    {FRENCHVANILLA, "French Vanilla"},
                                                    {STRAWBERRY, "Strawberry"},
                                                    {PEPPERMINT, "Peppermint"},
                                                    {MANGO, "Mango"}};
std::map<sizeType, std::string> drink::sizeToStr = {{SMALL, "Small"},
                                                    {MED, "Medium"},
                                                    {LARGE, "Large"}};
;
std::map<std::string, sizeType> drink::strToSize = {{"SMALL", SMALL},
                                                    {"MEDIUM", MED},
                                                    {"LARGE", LARGE}};
;
std::map<tempType, std::string> drink::tempToStr = {{HOT, "Hot"},
                                                    {ICE, "Iced"},
                                                    {BLEND, "Blended"}};
std::map<std::string, tempType> drink::strToTemp = {{"hot", HOT},
                                                    {"iced", ICE},
                                                    {"blended", BLEND}};
std::map<std::string, flavType> drink::strToFlav = {{"hazelnut", HAZELNUT},
                                                    {"apple", APPLE},
                                                    {"butter pecan", BUTTERPECAN},
                                                    {"blueberry", BLUEBERRY},
                                                    {"caramel", CARAMEL},
                                                    {"peach", PEACH},
                                                    {"mocha", MOCHA},
                                                    {"raspberry", RASPBERRY},
                                                    {"french vanilla", FRENCHVANILLA},
                                                    {"strawberry", STRAWBERRY},
                                                    {"peppermint", PEPPERMINT},
                                                    {"mango", MANGO}};

drink::drink(baseType b, tempType t, sizeType s, std::string d)
{
    base = b;
    temperature = t;
    size = s;
    dairy = d;
}

std::string drink::getBaseStr() const
{
    return baseToStr[base];
}

std::string drink::getTemperature() const
{
    return tempToStr[temperature];
}

std::string drink::getSize() const
{
    return sizeToStr[size];
}

std::string drink::getDairy() const
{
    return dairy;
}

std::string drink::getFlavor() const
{
    std::ostringstream out;
    if (flavors.size() == 0)
    {
        return "None";
    }
    std::set<flavType>::const_iterator it = flavors.begin();
    out << flavToStr[*it];
    for (++it; it != flavors.end(); ++it)
    {
        out << ", " << flavToStr[*it];
    }
    return out.str();
}

double drink::getPrice() const
{
    double price = 0;
    switch (size)
    {
    case SMALL:
        price = 2;
        break;
    case MED:
        price = 3;
        break;
    case LARGE:
        price = 4;
        break;
    }
    switch (base)
    {
    case COFFEE:
        price += 2.75;
        break;
    case TEA:
        price += 1.75;
        break;
    case CREAM:
        break;
    }
    switch (temperature)
    {
    case HOT:
        break;
    case ICE:
        price += .5;
        break;
    case BLEND:
        price += .75;
        break;
    }
    price += .25 * flavors.size();
    std::string lowerD = dairy;
    std::transform(lowerD.begin(), lowerD.end(), lowerD.begin(), ::tolower);
    if (lowerD == "whole milk")
    {
        price += .75;
    }
    else if (lowerD == "skim milk")
    {
        price += .75;
    }
    else if (lowerD == "cream")
    {
        price += 1.5;
    }
    else if (lowerD == "oat milk")
    {
        price += 2;
    }
    else if (lowerD == "almond milk")
    {
        price += 2;
    }
    else if (lowerD == "none" || lowerD == "")
    {
        price += 0;
    }
    else
    {
        price += .5;
    }

    return price;
}

void drink::setBase(baseType b)
{
    base = b;
}

void drink::setTemperature(tempType t)
{
    temperature = t;
}

void drink::setSize(sizeType s)
{
    size = s;
}

void drink::setDairy(std::string d)
{
    dairy = d;
}

void drink::addFlavor(flavType f)
{
    auto p = flavors.insert(f);
    if (p.second)
    {
        std::cout << "New flavor added" << std::endl;
    }
}

void drink::removeFlavor(flavType f)
{
    flavors.erase(f);
}

void drink::removeAllFlavor()
{
    flavors.clear();
}

std::string drink::tostring() const
{
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    out << getSize() << " - " << getTemperature() << ", " << getBaseStr() << ", " << getDairy() << ", " << getFlavor()
        << " - $" << getPrice() << std::endl;
    return out.str();
}

std::ostream &operator<<(std::ostream &out, const drink &d)
{
    out << d.tostring();
    return out;
}

drink::drink(std::string base, std::string temp, std::string size, std::string dairy)
{
    if (!strToSize.count(size))
    {
        throw sizeException(size);
    }
    if (!strToBase.count(base))
    {
        throw baseException(base);
    }
}