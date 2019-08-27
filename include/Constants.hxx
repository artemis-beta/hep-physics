#ifndef __CONSTANTS_HXX__
#define __CONSTANTS_HXX__

#include <string>
#include <exception>
#include <cmath>

#include "Units.hxx"

namespace HEP
{
    /*! @namespace HEP::Constants
    
    Namespace containing all physical constants

    @todo Finish all constant definitions
    
    @author K. Zarebski

    @copyright MIT License

    @date last modified 2019-08-27
    */

    namespace Constants
    {
        //! Constant of a circle @f$\pi@f$
        extern const double pi;
        //! Speed of light @f$ c@f$
        extern const double c;
        //! Avogadro's constant @f$N_A@f$
        extern const double N_A;
        //! Planck's constant @f$h@f$
        extern const double h;
        //! Reduced Planck's constant @f$\hbar@f$
        extern const double hbar;
        //! Electron charge
        extern const double e;
        //! Electron mass @f$m_e@f$
        extern const double m_e;
        //! Proton mass @f$m_p@f$
        extern const double m_p;
        //! Permitttivity of free space @f$\epsilon_0@f$
        extern const double epsilon_0;
    }
}

#endif