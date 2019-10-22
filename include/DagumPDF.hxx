#ifndef __DAGUM_HXX__
#define __DAGUM_HXX__

#include "PDF.hxx"
#include "Constants.hxx"
#include <cmath>

using namespace PHYS::PDF;

const double _dagum_invcdf(const double x, const Params p)
{
    return p[1]*pow(pow(p[0], -1./p[2])-1, -1./x);
}

namespace PHYS
{
    namespace PDF
    {
        /*! @brief  Dagum PDF Class
        @details    Class representing the Dagum PDF
        @version    0.1.0
        @author     Kristian Zarebski
        @date 	    last modified 2019-10-21
        @copyright  MIT License
        */
        class Dagum : public ProbabilityDensityFunction
        {
            public:
                Dagum(const double a, const double b, const double p) :
                    ProbabilityDensityFunction("Dagum", {a, b, p},_dagum_invcdf){}
        };
    };
};

#endif