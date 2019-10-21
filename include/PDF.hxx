#ifndef __PDF_HXX__
#define __PDF_HXX__

#include <map>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <iostream>

namespace PHYS
{
    /*! @namespace PHYS::PDF
    
    Namespace containing all probability distribution function classes

    @todo Finish all PDFs
    
    @author K. Zarebski

    @copyright MIT License

    @date last modified 2019-10-21
    */
    namespace PDF
    {
        typedef std::vector<double> Params;
        /*! @brief  ProbabilityDensityFunction Class
        @details    Class to produce a PDF for generating simulated datasets
        @version    0.1.0
        @author     Kristian Zarebski
        @date 	    last modified 2019-10-21
        @copyright  MIT License
        */
        class ProbabilityDensityFunction
        {
            private:
                const Params _params;
                const std::function<double(double, std::vector<double>)> _f;
            public:
                /*! Create a new nucleus object
            @param name          Name of PDF
            @param params        List of parameter values as an array of doubles
            @param inv_cdf       Inverse CDF defined using indices of parameter array
            */
                ProbabilityDensityFunction(const std::string name, const Params params, 
                                           const std::function<double(double, std::vector<double>)> inv_cdf) : _f(inv_cdf), _params(params)
                {
                    srand(time(NULL));
                }
                /*! Generate values
            @param nevts Number of values to generate using PDF
            */
                const std::vector<double> generate(const int nevts);
        };
    };
};

#endif