#include "Particle.hxx"

Particle::Particle(std::string _name, std::string _sign, double _mass, double _tau)
{
	name_ = _name;
	sign_ = _sign;
	momentum_ = HEPLorentzVector(_mass, 0, 0, 0);
	lifetime_ = _tau;
}

Particle::Particle(double e, double px, double py, double pz)
{
    momentum_ = HEPLorentzVector(e,px,py,pz);
}
void Particle::anti()
{
	if(sign_ == "+"){sign_ = "-";}
	if(sign_ == "0"){sign_ = "~0";}
}

double Particle::theta() 
{
    return atan(this->PT()/this->momentum()[3]);
}

void Particle::Fire(double energy)
{
	double e_ = pow(this->M()*this->M()+energy*energy, 0.5);
	momentum_  = HEPLorentzVector(e_, 0, 0, energy);
}	

double Particle::phi() 
{
    return atan(this->momentum()[1]/this->momentum()[2]);
}

double Particle::PT() 
{
    return pow(pow(this->momentum()[1],2)+pow(this->momentum()[2],2), 0.5);
}

double Particle::eta() 
{
    return -log(tan(this->theta()/2.));
}

double Particle::y()
{
	return 0.5*log((this->momentum()[0]+this->momentum()[3])/(this->momentum()[0]-this->momentum()[3]));
}

double Particle::M() 
{
    return momentum_.magnitude();
}

HEPLorentzVector Particle::momentum()
{
    return momentum_;
}
