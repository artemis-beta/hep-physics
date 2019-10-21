#ifndef __EXPO_HXX__
#define __EXPO_HXX__

#include "PDF.hxx"
#include "Constants.hxx"
#include <cmath>

using namespace PHYS::PDF;

const double _expo_invcdf(const double x, const Params p)
{
    return -log(1-x)/p[0];
}

namespace PHYS
{
    namespace PDF
    {
        /*! @brief  Exponential PDF Class
        @details    Class representing the Exponential PDF
        @version    0.1.0
        @author     Kristian Zarebski
        @date 	    last modified 2019-10-21
        @copyright  MIT License
        */
        class Exponential : public ProbabilityDensityFunction
        {
            public:
                Exponential(const double lambda) :
                    ProbabilityDensityFunction("Exponential", {lambda},_expo_invcdf){}
        };
    };
};

#endif