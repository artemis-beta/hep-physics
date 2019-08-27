#include "Particle.hxx"

std::ostream &operator<<(std::ostream &os, HEP::Particle  &p)
{
	os << p.getName();
	return os;
}

HEP::Particle::Particle()
{
	_name = "";
	_sign = "";
	_mass = -1;
	_momentum = HEP::LorentzVector();
	_lifetime = -1;
}

HEP::Particle::Particle(std::string name, std::string sign, double mass, double lifetime)
{
    _name = name;
	_sign = sign;
	_mass = mass;
	_momentum = HEP::LorentzVector(mass, 0, 0, 0);
	_lifetime = lifetime;
}

HEP::Particle::Particle(double e, double px, double py, double pz)
{
    _momentum = HEP::LorentzVector(e,px,py,pz);
}

HEP::Particle::operator bool() const
{
	if(_name == "" || _mass == -1 || _lifetime == -1)
	{
		return false;
	}

	return true;
}

const HEP::Particle HEP::Particle::anti() const
{
	HEP::Particle other = *this;
	if(other._sign == "+"){other._sign = "-";}
	else if(other._sign == "-"){other._sign = "+";}
	else if(other._sign == "0"){other._sign = "~0";}
	else{other._sign = "0";}
	return other;
}

const double HEP::Particle::theta() const
{
    return atan(this->PT()/this->momentum()[3]);
}

void HEP::Particle::Fire(double energy)
{
	double e_ = pow(this->M()*this->M()+energy*energy, 0.5);
	_momentum  = HEP::LorentzVector(e_, 0, 0, energy);
}	

const double HEP::Particle::phi() const
{
    return atan(this->momentum()[1]/this->momentum()[2]);
}

const double HEP::Particle::PT() const
{
    return pow(pow(this->momentum()[1],2)+pow(this->momentum()[2],2), 0.5);
}

const double HEP::Particle::eta() const
{
    return -log(tan(this->theta()/2.));
}

const double HEP::Particle::y() const
{
	return 0.5*log((this->momentum()[0]+this->momentum()[3])/(this->momentum()[0]-this->momentum()[3]));
}

const double HEP::Particle::M() const
{
    return _momentum.magnitude();
}

const HEP::LorentzVector HEP::Particle::momentum() const
{
    return _momentum;
}

const double HEP::Particle::P() const
{
	return pow(_momentum[1]*_momentum[1]+_momentum[2]*_momentum[2]+_momentum[3]*_momentum[3], 0.5);
}

const double HEP::Particle::beta(const int p_i) const
{
	if(p_i == 0){return this->P()/_momentum[0];}
	else{return _momentum[p_i]/_momentum[0];}
}

const double HEP::Particle::gamma() const
{
	return _momentum[0]/_mass;
}

const double HEP::Particle::ctau() const
{
	return HEP::Constants::c*_lifetime;
}