#ifndef __KPLUSDECTABLE__
#define __KPLUSDECTABLE__

#include "DecayTable.hxx"
#include "CommonParticles.hxx"

const PHYS::DecayTable gen_KplusDecays();

namespace PHYS
{
	//! DecayTable of all decays of the @f$ K^{\pm} @f$ meson. The @c gen_KplusDecay function generates all the relevant channels
	extern const DecayTable KplusDecays;
}

#endif
