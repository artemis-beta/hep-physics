#ifndef HEPLORENTZ_VECTOR_HXX
#define HEPLORENTZ_VECTOR_HXX

#include <math.h>
#include <iostream>

namespace HEP
{
    /*!	@brief  Lorentz Vector Class
	@details    Class to represent Lorentz vectors of the form e.g. four momenta
	@version	0.1.0
	@author     Kristian Zarebski
	@date 		last modified 2019-08-26 
	@copyright  MIT License
    */
    class LorentzVector {
        private:
            double x0=-9999, x1=-9999, x2=-9999, x3=-9999;
        public:
            //! Create a blank LorentzVector with the default values of -9999
            LorentzVector(){};
            //! Specify a component of the LorentzVector by index [0, 3] for @f$(x_0, x_1, x_2, x_3)@f$
            const double& operator[] (size_t i);
            //! Specify a component of the LorentzVector by index [0, 3] for @f$(x_0, x_1, x_2, x_3)@f$
            double operator[] (size_t i) const
            {
                return (*const_cast<LorentzVector*>(this))[i];
            }
            //! Output the components of the LorentzVector to the ostream when printing
            friend std::ostream& operator<<(std::ostream& os, const LorentzVector& lv);
            //! Create a new LorentzVector by giving the four values @f$(x_0, x_1, x_2, x_3)@f$
            LorentzVector(double x0, double x1, double x2, double x3);
            //! Returns the magnitude of the vector as @f$ r = \sqrt{x_0^2-x_1^2-x_2^2-x_3^2} @f$
            const double magnitude() const {return pow(x0*x0-x1*x1+x2*x2, 0.5);}
    };
}
#endif
