#include "EquationSolver.hxx"
#include <iostream>

using namespace PHYS;

int main()
{
    Equation eq = X/pow(X, 3);
    std::cout << "F(x) = " << eq << std::endl;
    double solution = eq.Solve(2.0);
    std::cout << "F(2) = " << solution << std::endl;
    return 0;
}