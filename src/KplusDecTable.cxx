#include "KplusDecTable.hxx"

const PHYS::DecayTable gen_KplusDecays()
{
	PHYS::DecayTable _tmp(PHYS::Particles::Kplus);
	
	std::vector<PHYS::Particle> _d = {PHYS::Particles::mu.anti(), 
	                            PHYS::Particles::nu_mu};

	PHYS::Decay _kdec = PHYS::Decay(_d, 0.6356);

	_tmp.addDecay(_kdec);
	
	_d = {PHYS::Particles::Piplus, 
	      PHYS::Particles::Pi0};

        _kdec = PHYS::Decay(_d, 0.2067);

        _tmp.addDecay(_kdec);
        
	_d = {PHYS::Particles::Piplus,
	      PHYS::Particles::Piplus,
	      PHYS::Particles::Piplus.anti()};

        _kdec = PHYS::Decay(_d, 0.05583);

        _tmp.addDecay(_kdec);
	
	_d = {PHYS::Particles::Pi0,
	      PHYS::Particles::e.anti(),
	      PHYS::Particles::nu_e};

        _kdec = PHYS::Decay(_d, 0.0507);

        _tmp.addDecay(_kdec);
	
	_d = {PHYS::Particles::Pi0, 
	      PHYS::Particles::mu.anti(),
	      PHYS::Particles::nu_mu};

        _kdec = PHYS::Decay(_d, 0.03352);

        _tmp.addDecay(_kdec);
	
	_d = {PHYS::Particles::Piplus,
	      PHYS::Particles::Pi0,
	      PHYS::Particles::Pi0};

        _kdec = PHYS::Decay(_d, 0.01760);

        _tmp.addDecay(_kdec);
	
	_d = {PHYS::Particles::Piplus,
	      PHYS::Particles::Piplus.anti(),
	      PHYS::Particles::e.anti(),
	      PHYS::Particles::nu_e};
        
	_kdec = PHYS::Decay(_d, 4.247E-5);

        _tmp.addDecay(_kdec);
	
	_d = {PHYS::Particles::Pi0, 
	      PHYS::Particles::Pi0,
	      PHYS::Particles::e.anti(), 
	      PHYS::Particles::nu_e};
        
	_kdec = PHYS::Decay(_d, 2.55E-5);

        _tmp.addDecay(_kdec);
	
	_d = {PHYS::Particles::e.anti(),
	      PHYS::Particles::nu_e};
        
	_kdec = PHYS::Decay(_d, 1.582E-5);

        _tmp.addDecay(_kdec);
	
	_d = {PHYS::Particles::Piplus, 
	PHYS::Particles::Piplus.anti(), 
	PHYS::Particles::mu.anti(), 
	PHYS::Particles::nu_mu};
        
	_kdec = PHYS::Decay(_d, 1.4E-5);

        _tmp.addDecay(_kdec);

        _d = {PHYS::Particles::Piplus, 
	      PHYS::Particles::mu, 
	      PHYS::Particles::mu.anti()};

        _kdec = PHYS::Decay(_d, 9.6E-8);

	_tmp.addDecay(_kdec);

	_d = {PHYS::Particles::Piplus, 
	      PHYS::Particles::e, 
	      PHYS::Particles::e.anti()};

	_kdec = PHYS::Decay(_d, 1.7E-7);

	_tmp.addDecay(_kdec);


	return _tmp;
}

const PHYS::DecayTable PHYS::KplusDecays = gen_KplusDecays();