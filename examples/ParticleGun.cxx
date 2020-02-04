#include "ParticleGun.hxx"
#include "CommonParticles.hxx"

using namespace PHYS;

int main()
{
	const Simulation::ParticleGun* _my_gun = new Simulation::ParticleGun(&Particles::Piplus, 1000., 0., 0.);

	std::cout << *_my_gun << std::endl;

	return 0;
}
