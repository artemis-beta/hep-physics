#ifndef __KPLUSDECTABLE__
#define __KPLUSDECTABLE__

#include "DecayTable.hxx"
#include "CommonParticles.hxx"

using namespace HEP;

DecayTable KplusDecays()
{
	DecayTable _tmp(Kplus);
	
	std::vector<Particle> _d = {mu.anti(), nu_mu};

	Decay _kdec = Decay(_d, 0.6356);

	_tmp.addDecay(_kdec);

        
	_d = {Piplus, Piplus, Piplus.anti()};

        _kdec = Decay(_d, 1E-2);

        _tmp.addDecay(_kdec);

        _d = {Piplus, mu, mu.anti()};

        _kdec = Decay(_d, 9.6E-8);

	_tmp.addDecay(_kdec);

	_d = {Piplus, e, e.anti()};

	_kdec = Decay(_d, 1.7E-7);

	_tmp.addDecay(_kdec);


	return _tmp;
}

#endif
