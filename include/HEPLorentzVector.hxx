#ifndef HEPLORENTZ_VECTOR_HXX
#define HEPLORENTZ_VECTOR_HXX

#include <math.h>
#include <iostream>

class HEPLorentzVector {
    private:
        double x0=-9999, x1=-9999, x2=-9999, x3=-9999;
    public:
	HEPLorentzVector(){};
        double& operator[] (size_t i);
        double operator[] (size_t i) const
        {
            return (*const_cast<HEPLorentzVector*>(this))[i];
        }
        friend std::ostream& operator<<(std::ostream& os, const HEPLorentzVector& lv);
        HEPLorentzVector(double x0, double x1, double x2, double x3);
        double magnitude(){return pow(x0*x0-x1*x1+x2*x2, 0.5);}
};

#endif
