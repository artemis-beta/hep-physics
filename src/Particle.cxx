#include "Particle.hxx"

Particle::Particle(double e, double px, double py, double pz):

    momentum_(e,px,py,pz){ std::cout << e << std::endl;}

double Particle::theta()
{
    return atan(this->PT()/this->momentum()[3]);
}

double Particle::phi()
{
    return atan(this->momentum()[0]/this->momentum()[1]);
}

double Particle::PT()
{
    return pow(pow(this->momentum()[0],2)+pow(this->momentum()[1],2), 0.5);
}

double Particle::eta()
{
    return -1*log(tan(this->theta()/2.));
}

double Particle::M()
{
    return momentum_.magnitude();
}

HEPLorentzVector &Particle::momentum()
{
    return momentum_;
}
