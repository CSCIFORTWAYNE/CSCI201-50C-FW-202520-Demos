#include <cpr/cpr.h>
#include <iostream>

// cpr library found at https://github.com/libcpr/cpr

int main(int argc, char **argv)
{
    cpr::Response r = cpr::Get(cpr::Url{"https://netbsd.org"});
    std::cout << r.status_code << std::endl;
    std::cout << r.header["content-type"] << std::endl;
    std::cout << r.text << std::endl;
    return 0;
}