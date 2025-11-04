#include "product.h"

int main()
{
    product myProduct(23, "My first product", 3.99, 2);
    drink::flavType flav[2] = {drink::APPLE,
                               drink::BLUEBERRY};
    drink myDrink(true, false, drink::sizeType::LRG, flav, 2);
    myProduct.getPrice();
    // myProduct.price;
    // myDrink.getDescription();
    return 0;
}