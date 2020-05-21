#include "gtest/gtest.h"
#include "EquationSolver.hxx"

#include <random>
#include "boost/format.hpp"

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(2,9);

using namespace PHYS::Algebra;

TEST(TestEquation, TestSimplify)
{
	const int n_trials = 10;
	for(int i{0}; i < n_trials; ++i)
	{
		const std::vector<int> _poly_comp = {uni(rng), uni(rng), uni(rng), uni(rng)};
		const boost::format _format = boost::format("%1%x^2+%2%x = %3%") % _poly_comp[0] % _poly_comp[1] % (_poly_comp[3]-_poly_comp[2]);
		const Equation test_eq(_poly_comp[0]*X*X+_poly_comp[1]*X+_poly_comp[2], _poly_comp[3]);
		const std::string eq_str = test_eq.toString();

		std::cout << " "+std::string(4, '-')+" Trial "+std::to_string(i)+" "+std::string(4, '-')+" Testing Equation: " << _format.str() << std::endl;

		EXPECT_EQ(_format.str(), eq_str);
	}
}
