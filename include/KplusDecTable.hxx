#ifndef __KPLUSDECTABLE__
#define __KPLUSDECTABLE__

#include "DecayTable.hxx"
#include "CommonParticles.hxx"

using namespace HEP;

const DecayTable gen_KplusDecays()
{
	DecayTable _tmp(Kplus);
	
	std::vector<Particle> _d = {mu.anti(), nu_mu};

	Decay _kdec = Decay(_d, 0.6356);

	_tmp.addDecay(_kdec);
	
	_d = {Piplus, Pi0};

        _kdec = Decay(_d, 0.2067);

        _tmp.addDecay(_kdec);
        
	_d = {Piplus, Piplus, Piplus.anti()};

        _kdec = Decay(_d, 0.05583);

        _tmp.addDecay(_kdec);
	
	_d = {Pi0, e.anti(), nu_e};

        _kdec = Decay(_d, 0.0507);

        _tmp.addDecay(_kdec);
	
	_d = {Pi0, mu.anti(), nu_mu};

        _kdec = Decay(_d, 0.03352);

        _tmp.addDecay(_kdec);
	
	_d = {Piplus, Pi0, Pi0};

        _kdec = Decay(_d, 0.01760);

        _tmp.addDecay(_kdec);
	
	_d = {Piplus, Piplus.anti(), e.anti(), nu_e};
        
	_kdec = Decay(_d, 4.247E-5);

        _tmp.addDecay(_kdec);
	
	_d = {Pi0, Pi0, e.anti(), nu_e};
        
	_kdec = Decay(_d, 2.55E-5);

        _tmp.addDecay(_kdec);
	
	_d = {e.anti(), nu_e};
        
	_kdec = Decay(_d, 1.582E-5);

        _tmp.addDecay(_kdec);
	
	_d = {Piplus, Piplus.anti(), mu.anti(), nu_mu};
        
	_kdec = Decay(_d, 1.4E-5);

        _tmp.addDecay(_kdec);

        _d = {Piplus, mu, mu.anti()};

        _kdec = Decay(_d, 9.6E-8);

	_tmp.addDecay(_kdec);

	_d = {Piplus, e, e.anti()};

	_kdec = Decay(_d, 1.7E-7);

	_tmp.addDecay(_kdec);


	return _tmp;
}

namespace HEP
{
	//! DecayTable of all decays of the @f$ K^{\pm} @f$ meson. The @c gen_KplusDecay function generates all the relevant channels
	extern const DecayTable KplusDecays = gen_KplusDecays();
}

#endif
