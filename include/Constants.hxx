#ifndef __CONSTANTS_HXX__
#define __CONSTANTS_HXX__

#include <string>
#include <exception>
#include <cmath>

#include "Units.hxx"

namespace PHYS
{
    /*! @namespace PHYS::Constants
    
    Namespace containing all physical constants
    
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
        //! Permeability of free space @f$\mu_0@f$
        extern const double mu_0;
        //! Fine structure constant @f$ \alpha@f$
        extern const double alpha;
        //! Classical electron radius @f$r_e@f$
        extern const double r_e;
        //! Bohr radius (mass of nucleus is infinite) @f$r_{Bohr}@f$
        extern const double r_bohr;
        //! Thomson cross section @f$\sigma_T@f$
        extern const double sigma_T;
        //! Bohr magneton @f$\mu_B@f$
        extern const double mu_B;
        //! Nuclear magneton @f\mu_N@f$
        extern const double mu_N;
        //! Gravitational Constant @f$G@f$
        extern const double G;
        //! Standard gravitational acceleration @f$g@f$
        extern const double g;
        //! Boltzmann constant @f$ k@f$
        extern const double k;
        //! Wien constant @f$b@f$
        extern const double b;
        //! Stefan-Boltzmann constant @f$\sigma@f$
        extern const double sigma;
        //! Strong coupling constant @f$\alpha_s@f$
        extern const double alpha_s;
        //! Exponential number
        extern const double exp;
        //! Planck Mass
        extern const double m_planck;
        //! Planck Length
        extern const double l_planck;
        //! Atomic mass unit
        extern const double u;
        //! Gas Constant
        extern const double R;
    }
}

#endif