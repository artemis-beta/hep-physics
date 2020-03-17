#ifndef __UNITS_HXX__
#define __UNITS_HXX__

#include <string>
#include <exception>

namespace PHYS
{
    /*! @namespace PHYS::Units
    
    Namespace containing all units for easy conversion to SI units
    for calculations
    
    @author K. Zarebski

    @copyright MIT License

    @date last modified 2019-08-27
    */

    namespace Units
    {
        const extern double cd;

        const extern double m;
        const extern double mm;
        const extern double nm;
        const extern double km;
        const extern double cm;
        const extern double angstrom;
        const extern double mile;
        const extern double yd;
        const extern double AU;
        const extern double pc;
        const extern double inch;

        const extern double kg;
        const extern double t;
        const extern double g;

        const extern double sec;
        const extern double yr;
        const extern double day;
        const extern double hr;
        const extern double min;
        const extern double ms;
        const extern double ns;
        const extern double ps;
        
        const extern double J;
        const extern double eV;
        const extern double keV;
        const extern double MeV;
        const extern double GeV;
        const extern double TeV;
        const extern double erg;

        const extern double b;
        const extern double mb;
        const extern double nb;
        const extern double pb;
        const extern double fb;

        const extern double inv_pb;
        const extern double inv_fb;

        const extern double N;
        const extern double dyne;
        const extern double kN;

        const extern double A;
        const extern double V;
        const extern double C;
        const extern double F;
        const extern double W;
        const extern double Ohms;
        const extern double S;
        const extern double Wb;
        const extern double H;
        const extern double esu;

        const extern double K;
        const extern double Celsius(const double& kelvin);
        const extern double Fahrenheit(const double& kelvin);

        const extern double T;
        const extern double G;

        const extern double Pa;
        const extern double atm;
        const extern double Torr;

        const extern double rad;
        const extern double deg;
        const extern double sr;

        const extern double Hz;

        const extern double lm;
        const extern double lx;

        const extern double Bq;

        const extern double Gy;
        const extern double Sv;

        const extern double kat;

        const extern double mol;
    }
}

#endif