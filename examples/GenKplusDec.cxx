#include <iostream>
#include "DecayTable.hxx"
#include "CommonParticles.hxx"
#include "KplusDecTable.hxx"

#include <vector>

using namespace HEP;

int main(void)
{
	srand (time(NULL));

	for(int i{0}; i<10; ++i)
	{
		std::cout << "Generating Random K+ Decay...\n" << std::endl;
		std::cout << KplusDecays().getRandom().getDecStr() << std::endl;
	}
}
