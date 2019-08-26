#ifndef HEPLORENTZ_VECTOR_HXX
#define HEPLORENTZ_VECTOR_HXX

#include <math.h>
#include <iostream>

namespace HEP
{
    /*!	@brief      Lorentz Vector Class
	@details    Class to represent Lorentz vectors of the form e.g. four momenta
	@version	0.1.0
	@author     Kristian Zarebski
	@date 		last modified 2019-08-25 
	@copyright  MIT License
    */
    class LorentzVector {
        private:
            double x0=-9999, x1=-9999, x2=-9999, x3=-9999;
        public:
            LorentzVector(){};
            double& operator[] (size_t i);
            double operator[] (size_t i) const
            {
                return (*const_cast<LorentzVector*>(this))[i];
            }
            friend std::ostream& operator<<(std::ostream& os, const LorentzVector& lv);
            LorentzVector(double x0, double x1, double x2, double x3);
            double magnitude(){return pow(x0*x0-x1*x1+x2*x2, 0.5);}
    };
}
#endif
