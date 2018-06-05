#include <iostream>
#include "DecayTable.hxx"
#include "CommonParticles.hxx"
#include "KplusDecTable.hxx"

#include <vector>

using namespace HEP;

int main(void)
{
	std::cout << "Generating Random K+ Decay...\n" << std::endl;
	std::cout << KplusDecays().getRandom().getDecStr() << std::endl;
}
