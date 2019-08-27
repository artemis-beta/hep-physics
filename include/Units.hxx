#ifndef __UNITS_HXX__
#define __UNITS_HXX__

#include <string>
#include <exception>

namespace HEP
{
    /*! @namespace HEP::Units
    
    Namespace containing all units for easy conversion to SI units
    for calculations

    @todo Finish all unit definitions
    
    @author K. Zarebski

    @copyright MIT License

    @date last modified 2019-08-26
    */

    namespace Units
    {
        const extern double m;
        const extern double mm;
        const extern double nm;
        const extern double km;
        const extern double cm;
        const extern double angstrom;
        const extern double mile;
        const extern double yd;
        const extern double AU;

        const extern double kg;
        const extern double t;

        const extern double sec;
        const extern double ms;
        const extern double ns;
        const extern double ps;
        
        const extern double J;
        const extern double eV;
        const extern double keV;
        const extern double MeV;
        const extern double GeV;
        const extern double TeV;

        const extern double b;
        const extern double mb;
        const extern double nb;
        const extern double pb;
        const extern double fb;

        const extern double inv_pb;
        const extern double inv_fb;

        const extern double N;
        const extern double kN;

        const extern double C;
        const extern double F;
    }
}

#endif