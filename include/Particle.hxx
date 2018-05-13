#ifndef PARTICLE_HXX
#define PARTICLE_HXX

#include <iostream>
#include <math.h>

#include <string>
#include "HEPLorentzVector.hxx"

class Particle {
    std::string name_="X";
    std::string sign_="";
    double mass_     = -1;
    double lifetime_ = -1;
    HEPLorentzVector momentum_;
    public:
        Particle();
        Particle(std::string, std::string, double, double);
        Particle(double,double,double,double);
	std::string getName() {return name_+sign_;}
	Particle anti();
	void Fire(double);
        double M() ;
        double phi() ;
	double y() ;
        double eta() ;
        double theta() ;
        HEPLorentzVector momentum();
        double PT() ;
        friend std::ostream &operator<<(std::ostream &, Particle  &);
};

#endif
