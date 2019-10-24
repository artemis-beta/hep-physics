#include "EquationSolver.hxx"
#include <iostream>

using namespace PHYS;

int main()
{
    Equation eq = X*X+2*Y+1;
    Equation eq2 = 4*X+1;
    std::cout << "EQ1: " << eq << std::endl;
    std::cout << "EQ2: " << eq2 << std::endl;
    std::cout << eq*eq2 << std::endl;
    return 0;
}