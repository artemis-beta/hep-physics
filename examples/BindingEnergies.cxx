#include <iostream>
#include <cmath>

#include "CommonNuclei.hxx"
#include "NuclearPhysics.hxx"
#include "Units.hxx"

int main()
{
	PHYS::Nucleus n = PHYS::Elements::Nitrogen;

	std::cout << "The mass defect energy of Nitrogen is " << n.mass_defect()*pow(PHYS::Constants::c,2)/PHYS::Units::keV << "keV" << std::endl;
	std::cout << "The Binding Energy per Nucleon is " << PHYS::getBindingEnergyPerNucleon(&n) << "MeV" << std::endl;

	return 0;

}
