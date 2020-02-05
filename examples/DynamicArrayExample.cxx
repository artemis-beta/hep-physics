#include "DynamicArray.hxx"

#include <iostream>

using namespace PHYS::Data;

int main()
{
    DynamicArray<double> a({20,30,40,50},"a");
    DynamicArray<double> b({10,4,5,3},"b");

    std::cout << "STARTING ARRAYS: " << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << "PUSH BACK: " << std::endl;
    a.push_back(20.);
    b.push_back(3.);
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << "NEGATIVE: " << std::endl;

    std::cout << -a << std::endl;
    std::cout << -b << std::endl;

    std::cout << "MULTIPLY BY 10: " << std::endl;

    a *= 10;
    b *= 10;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << "a + b : " << std::endl;

    std::cout << b+a << std::endl;

    std::cout << "TEST MEM HANDLING: " << std::endl;

    DynamicArray<double> c(a, "c");

    c *= 5;

    std::cout << a << std::endl;
    std::cout << c << std::endl;

    return 0;
}