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
