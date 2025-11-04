#include "product.h"

// lecture activity M02-a create another derived class from product.
// Turn in your class's part of the .h and .cpp files

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