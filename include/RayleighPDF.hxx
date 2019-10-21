#ifndef __RAYLEIGH_HXX__
#define __RAYLEIGH_HXX__

#include "PDF.hxx"
#include "Constants.hxx"
#include <cmath>

using namespace PHYS::PDF;

const double _rayleigh_invcdf(const double x, const Params p)
{
    return std::pow(-1*std::log(1-x)*2*std::pow(p[0], 2),0.5);
}

namespace PHYS
{
    namespace PDF
    {
        /*! @brief  Rayleigh PDF Class
        @details    Class representing the Rayleigh PDF
        @version    0.1.0
        @author     Kristian Zarebski
        @date 	    last modified 2019-10-21
        @copyright  MIT License
        */
        class Rayleigh : public ProbabilityDensityFunction
        {
            public:
                Rayleigh(const double sigma) :
                    ProbabilityDensityFunction("Rayleigh", {sigma}, _rayleigh_invcdf){}
        };
    };
};

#endif