#include "Particle.hxx"

std::ostream &operator<<(std::ostream &os, HEP::Particle  &p)
{
	os << p.getName();
	return os;
}

HEP::Particle::Particle()
{
	name_ = "";
	sign_ = "";
	mass_ = -1;
	momentum_ = HEP::LorentzVector();
	lifetime_ = -1;
}

HEP::Particle::Particle(std::string _name, std::string _sign, double _mass, double _tau)
{
    name_ = _name;
	sign_ = _sign;
	mass_ = _mass;
	momentum_ = HEP::LorentzVector(_mass, 0, 0, 0);
	lifetime_ = _tau;
}

HEP::Particle::Particle(double e, double px, double py, double pz)
{
    momentum_ = HEP::LorentzVector(e,px,py,pz);
}

HEP::Particle::operator bool() const
{
	if(name_ == "" || mass_ == -1 || lifetime_ == -1)
	{
		return false;
	}

	return true;
}

const HEP::Particle HEP::Particle::anti() const
{
	HEP::Particle other = *this;
	if(other.sign_ == "+"){other.sign_ = "-";}
	else if(other.sign_ == "-"){other.sign_ = "+";}
	else if(other.sign_ == "0"){other.sign_ = "~0";}
	else{other.sign_ = "0";}
	return other;
}

const double HEP::Particle::theta() const
{
    return atan(this->PT()/this->momentum()[3]);
}

void HEP::Particle::Fire(double energy)
{
	double e_ = pow(this->M()*this->M()+energy*energy, 0.5);
	momentum_  = HEP::LorentzVector(e_, 0, 0, energy);
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
    return momentum_.magnitude();
}

const HEP::LorentzVector HEP::Particle::momentum() const
{
    return momentum_;
}

const double HEP::Particle::P() const
{
	return pow(momentum_[1]*momentum_[1]+momentum_[2]*momentum_[2]+momentum_[3]*momentum_[3], 0.5);
}

const double HEP::Particle::beta(const int p_i) const
{
	if(p_i == 0){return this->P()/momentum_[0];}
	else{return momentum_[p_i]/momentum_[0];}
}

const double HEP::Particle::gamma() const
{
	return momentum_[0]/mass_;
}

const double HEP::Particle::ctau() const
{
	return HEP::Constants::c*lifetime_;
}