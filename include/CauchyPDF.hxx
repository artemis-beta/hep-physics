#ifndef __CAUCHY_HXX__
#define __CAUCHY_HXX__

#include "PDF.hxx"
#include "Constants.hxx"
#include <math.h>

using namespace PHYS::PDF;

const double _cauchy_cdf(const double x, const Params p)
{
    return pow(PHYS::Constants::pi, -1)*atan((x-p[0])/p[1]) + 0.5;
}

namespace PHYS
{
    namespace PDF
    {
        /*! @brief  Cauchy Class
        @details    Class representing the Cauchy/Breit-Wigner PDF
        @version    0.1.0
        @author     Kristian Zarebski
        @date 	    last modified 2019-10-21
        @copyright  MIT License
        */
        class Cauchy : public ProbabilityDensityFunction
        {
            public:
                Cauchy(const double x0, const double gamma) :
                    ProbabilityDensityFunction("Cauchy", {x0, gamma},_cauchy_cdf){}
        };
    };
};

#endif