#ifndef __CAUCHY_HXX__
#define __CAUCHY_HXX__

#include "PDF.hxx"
#include "Constants.hxx"
#include <cmath>

using namespace PHYS::PDF;

const double _cauchy_invcdf(const double x, const Params p)
{
    return p[1]*tan((x-0.5)*PHYS::Constants::pi)+p[0];
}

namespace PHYS
{
    namespace PDF
    {
        /*! @brief  Cauchy PDF Class
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
                    ProbabilityDensityFunction("Cauchy", {x0, gamma},_cauchy_invcdf){}
        };
    };
};

#endif