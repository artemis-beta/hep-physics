#ifndef __GEOMETRIC_HXX__
#define __GEOMETRIC_HXX__

#include "PDF.hxx"
#include "Constants.hxx"
#include <cmath>

using namespace PHYS::PDF;

const double _geom_invcdf(const double x, const Params p)
{
    return log(1-x)/log(1-p[0]);
}

namespace PHYS
{
    namespace PDF
    {
        /*! @brief  Geometric PDF Class
        @details    Class representing the Geometric PDF
        @version    0.1.0
        @author     Kristian Zarebski
        @date 	    last modified 2019-10-21
        @copyright  MIT License
        */
        class Geometric : public ProbabilityDensityFunction
        {
            public:
                Geometric(const double p) :
                    ProbabilityDensityFunction("Geometric", {p},_geom_invcdf){}
        };
    };
};

#endif