#include "Particle.hxx"

using namespace HEP;

std::ostream &operator<<(std::ostream &os, Particle  &p)
{
	os << p.getName();
	return os;
}

Particle::Particle()
{
	name_ = "";
	sign_ = "";
	mass_ = -1;
	momentum_ = LorentzVector();
	lifetime_ = -1;
}

Particle::Particle(std::string _name, std::string _sign, double _mass, double _tau)
{
    name_ = _name;
	sign_ = _sign;
	mass_ = _mass;
	momentum_ = LorentzVector(_mass, 0, 0, 0);
	lifetime_ = _tau;
}

Particle::Particle(double e, double px, double py, double pz)
{
    momentum_ = LorentzVector(e,px,py,pz);
}

Particle::operator bool() const
{
	if(name_ == "" || mass_ == -1 || lifetime_ == -1)
	{
		return false;
	}

	return true;
}

const Particle Particle::anti() const
{
	Particle other = *this;
	if(other.sign_ == "+"){other.sign_ = "-";}
	else if(other.sign_ == "-"){other.sign_ = "+";}
	else if(other.sign_ == "0"){other.sign_ = "~0";}
	else{other.sign_ = "0";}
	return other;
}

const double Particle::theta() const
{
    return atan(this->PT()/this->momentum()[3]);
}

void Particle::Fire(double energy)
{
	double e_ = pow(this->M()*this->M()+energy*energy, 0.5);
	momentum_  = LorentzVector(e_, 0, 0, energy);
}	

const double Particle::phi() const
{
    return atan(this->momentum()[1]/this->momentum()[2]);
}

const double Particle::PT() const
{
    return pow(pow(this->momentum()[1],2)+pow(this->momentum()[2],2), 0.5);
}

const double Particle::eta() const
{
    return -log(tan(this->theta()/2.));
}

const double Particle::y() const
{
	return 0.5*log((this->momentum()[0]+this->momentum()[3])/(this->momentum()[0]-this->momentum()[3]));
}

const double Particle::M() const
{
    return momentum_.magnitude();
}

const LorentzVector Particle::momentum() const
{
    return momentum_;
}
