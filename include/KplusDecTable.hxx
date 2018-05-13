#ifndef __KPLUSDECTABLE__
#define __KPLUSDECTABLE__

#include "DecayTable.hxx"
#include "CommonParticles.hxx"

DecayTable KplusDecays()
{
	DecayTable _tmp(Kplus);

        std::vector<Particle> _k3pi_d = {Piplus, Piplus, Piplus.anti()};

        Decay _k3pi = Decay(_k3pi_d, 1E-2);

        _tmp.addDecay(_k3pi);

	return _tmp;
}

#endif
