#include <iostream>
#include <cmath>

#include "CommonNuclei.hxx"
#include "NuclearPhysics.hxx"
#include "Units.hxx"

int main()
{
	HEP::Nucleus n = HEP::Elements::Nitrogen;

	std::cout << "The mass defect energy of Nitrogen is " << n.mass_defect()*pow(HEP::Constants::c,2)/HEP::Units::keV << "keV" << std::endl;
	std::cout << "The Binding Energy per Nucleon is " << HEP::getBindingEnergyPerNucleon(&n) << "MeV" << std::endl;

	return 0;

}
