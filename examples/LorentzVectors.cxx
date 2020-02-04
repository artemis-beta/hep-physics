#include "LorentzVector.hxx"

#include <iostream>

using namespace PHYS;

int main()
{
    const LorentzVector a(20, 20, 4, 20), b(50, 2, 2, 2);
    std::cout << a+b << std::endl;

    return 0;
}