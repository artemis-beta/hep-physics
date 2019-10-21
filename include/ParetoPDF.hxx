#ifndef __PARETO_HXX__
#define __PARETO_HXX__

#include "PDF.hxx"
#include <cmath>

using namespace PHYS::PDF;

double _pareto_invcdf(double x, const Params p)
{
    return p[0]/std::pow(1-x,1./p[1]);
}

namespace PHYS
{
    namespace PDF
    {
        /*! @brief  Pareto Class
        @details    Class representing the Pareto PDF
        @version    0.1.0
        @author     Kristian Zarebski
        @date 	    last modified 2019-10-21
        @copyright  MIT License
        */
        class Pareto : public ProbabilityDensityFunction
        {
            public:
                Pareto(const double xm, const double alpha) :
                    ProbabilityDensityFunction("Pareto", {xm, alpha},_pareto_invcdf){}
        };
    };
};
#endif