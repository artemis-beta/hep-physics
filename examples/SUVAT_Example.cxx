#include "ClassicalMechanics.hxx"
#include "Units.hxx"

#include <cmath>

using namespace PHYS;
using namespace PHYS::Units;

int main(int argc, char** argv)
{
	SUVATSolver solver(1E-38, 0, 1E-38, 6.7*m/pow(sec,2), 4*sec);

	std::cout << solver << std::endl;

	return 0;
}
