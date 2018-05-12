#ifndef PARTICLE_HXX
#define PARTICLE_HXX

#include <iostream>
#include <math.h>

#include <string>
#include "HEPLorentzVector.hxx"
#include "DecayTable.hxx"

class DecayTable;
class Particle {
    std::string name_="X";
    std::string sign_="";
    double lifetime_ = -1;
    HEPLorentzVector momentum_;
    DecayTable *_decays;
    public:
        Particle();
        Particle(std::string, std::string, double, double);
        Particle(double,double,double,double);
	std::string getName() {return name_+sign_;}
	void anti();
	DecayTable * getDecays(){return _decays;}
	void Fire(double);
        double M() ;
        double phi() ;
	double y() ;
        double eta() ;
        double theta() ;
        HEPLorentzVector momentum();
        double PT() ;
};

inline std::ostream &operator<<(std::ostream &os, Particle  &p)
{
	return os << p.getName() << "(" << p.M() << ")";
}
#endif
