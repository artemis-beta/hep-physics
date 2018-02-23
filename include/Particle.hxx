#ifndef PARTICLE_HXX
#define PARTICLE_HXX

#include <iostream>
#include <math.h>

#include <string>
#include "HEPLorentzVector.hxx"

class Particle {
    std::string name_;
    HEPLorentzVector momentum_;
    double M_;
    public:
        Particle(double,double,double,double);
        double M();
        double phi();
        double eta();
        double theta();
        HEPLorentzVector &momentum();
        double PT();
};

#endif
