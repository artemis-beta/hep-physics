#include "KplusDecTable.hxx"

const HEP::DecayTable gen_KplusDecays()
{
	HEP::DecayTable _tmp(HEP::Particles::Kplus);
	
	std::vector<HEP::Particle> _d = {HEP::Particles::mu.anti(), 
	                            HEP::Particles::nu_mu};

	HEP::Decay _kdec = HEP::Decay(_d, 0.6356);

	_tmp.addDecay(_kdec);
	
	_d = {HEP::Particles::Piplus, 
	      HEP::Particles::Pi0};

        _kdec = HEP::Decay(_d, 0.2067);

        _tmp.addDecay(_kdec);
        
	_d = {HEP::Particles::Piplus,
	      HEP::Particles::Piplus,
	      HEP::Particles::Piplus.anti()};

        _kdec = HEP::Decay(_d, 0.05583);

        _tmp.addDecay(_kdec);
	
	_d = {HEP::Particles::Pi0,
	      HEP::Particles::e.anti(),
	      HEP::Particles::nu_e};

        _kdec = HEP::Decay(_d, 0.0507);

        _tmp.addDecay(_kdec);
	
	_d = {HEP::Particles::Pi0, 
	      HEP::Particles::mu.anti(),
	      HEP::Particles::nu_mu};

        _kdec = HEP::Decay(_d, 0.03352);

        _tmp.addDecay(_kdec);
	
	_d = {HEP::Particles::Piplus,
	      HEP::Particles::Pi0,
	      HEP::Particles::Pi0};

        _kdec = HEP::Decay(_d, 0.01760);

        _tmp.addDecay(_kdec);
	
	_d = {HEP::Particles::Piplus,
	      HEP::Particles::Piplus.anti(),
	      HEP::Particles::e.anti(),
	      HEP::Particles::nu_e};
        
	_kdec = HEP::Decay(_d, 4.247E-5);

        _tmp.addDecay(_kdec);
	
	_d = {HEP::Particles::Pi0, 
	      HEP::Particles::Pi0,
	      HEP::Particles::e.anti(), 
	      HEP::Particles::nu_e};
        
	_kdec = HEP::Decay(_d, 2.55E-5);

        _tmp.addDecay(_kdec);
	
	_d = {HEP::Particles::e.anti(),
	      HEP::Particles::nu_e};
        
	_kdec = HEP::Decay(_d, 1.582E-5);

        _tmp.addDecay(_kdec);
	
	_d = {HEP::Particles::Piplus, 
	HEP::Particles::Piplus.anti(), 
	HEP::Particles::mu.anti(), 
	HEP::Particles::nu_mu};
        
	_kdec = HEP::Decay(_d, 1.4E-5);

        _tmp.addDecay(_kdec);

        _d = {HEP::Particles::Piplus, 
	      HEP::Particles::mu, 
	      HEP::Particles::mu.anti()};

        _kdec = HEP::Decay(_d, 9.6E-8);

	_tmp.addDecay(_kdec);

	_d = {HEP::Particles::Piplus, 
	      HEP::Particles::e, 
	      HEP::Particles::e.anti()};

	_kdec = HEP::Decay(_d, 1.7E-7);

	_tmp.addDecay(_kdec);


	return _tmp;
}

const HEP::DecayTable HEP::KplusDecays = gen_KplusDecays();