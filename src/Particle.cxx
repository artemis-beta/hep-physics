#include "Particle.hxx"

std::ostream &operator<<(std::ostream &os, PHYS::Particle  &p)
{
	os << p.getName();
	return os;
}

PHYS::Particle::Particle()
{
	_name = "";
	_sign = "";
	_mass = -1;
	_momentum = PHYS::LorentzVector();
	_lifetime = -1;
}

PHYS::Particle::Particle(std::string name, std::string sign, double mass, double lifetime)
{
    _name = name;
	_sign = sign;
	_mass = mass;
	_momentum = PHYS::LorentzVector(mass, 0, 0, 0);
	_lifetime = lifetime;
}

PHYS::Particle::Particle(double e, double px, double py, double pz)
{
    _momentum = PHYS::LorentzVector(e,px,py,pz);
}

PHYS::Particle::operator bool() const
{
	if(_name == "" || _mass == -1 || _lifetime == -1)
	{
		return false;
	}

	return true;
}

const PHYS::Particle PHYS::Particle::anti() const
{
	PHYS::Particle other = *this;
	if(other._sign == "+"){other._sign = "-";}
	else if(other._sign == "-"){other._sign = "+";}
	else if(other._sign == "0"){other._sign = "~0";}
	else{other._sign = "0";}
	return other;
}

const double PHYS::Particle::theta() const
{
    return atan(this->PT()/this->momentum()[3]);
}

void PHYS::Particle::Fire(double energy)
{
	double e_ = pow(this->M()*this->M()+energy*energy, 0.5);
	_momentum  = PHYS::LorentzVector(e_, 0, 0, energy);
}	

const double PHYS::Particle::phi() const
{
    return atan(this->momentum()[1]/this->momentum()[2]);
}

const double PHYS::Particle::PT() const
{
    return pow(pow(this->momentum()[1],2)+pow(this->momentum()[2],2), 0.5);
}

const double PHYS::Particle::eta() const
{
    return -log(tan(this->theta()/2.));
}

const double PHYS::Particle::y() const
{
	return 0.5*log((this->momentum()[0]+this->momentum()[3])/(this->momentum()[0]-this->momentum()[3]));
}

const double PHYS::Particle::M() const
{
    return _momentum.magnitude();
}

const PHYS::LorentzVector PHYS::Particle::momentum() const
{
    return _momentum;
}

const double PHYS::Particle::P() const
{
	return pow(_momentum[1]*_momentum[1]+_momentum[2]*_momentum[2]+_momentum[3]*_momentum[3], 0.5);
}

const double PHYS::Particle::beta(const int p_i) const
{
	if(p_i == 0){return this->P()/_momentum[0];}
	else{return _momentum[p_i]/_momentum[0];}
}

const double PHYS::Particle::gamma() const
{
	return _momentum[0]/_mass;
}

const double PHYS::Particle::ctau() const
{
	return PHYS::Constants::c*_lifetime;
}