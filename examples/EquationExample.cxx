#include "EquationSolver.hxx"
#include <iostream>

using namespace PHYS::Algebra;

int main()
{
    Equation eq(X*X+1, 2);
    std::cout << eq <<std::endl;
    return 0;
}
