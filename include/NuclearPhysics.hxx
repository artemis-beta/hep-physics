#ifndef __NUCLEAR_HXX__
#define __NUCLEAR_HXX__

#include <string>
#include <cmath>
#include <iostream>

#include "Constants.hxx"

namespace PHYS
{
    /*! @brief  Nucleus Class
	@details    Class representing a nucleus which can be used to construct the elements
	@version    0.1.0
	@author     Kristian Zarebski
	@date 	    last modified 2019-08-27
	@copyright  MIT License
        */
    class Nucleus
    {
        private:
            std::string _name;
            int _n_protons;
            int _n_neutrons;
            double _atomic_mass;
        public:
            /*! Create a new nucleus object
            @param name          Symbol/Name of nucleus
            @param atomic_number Number of protons/Atomic number @f$Z@f$
            @param atomic_mass   Mass of the nucleus in atomic mass units
            */
            Nucleus(const std::string name, const int atomic_number, const double atomic_mass) :
                    _name(name), 
                    _n_protons(atomic_number),
                    _n_neutrons(round(atomic_mass)),
                    _atomic_mass(atomic_mass) 
                    {
                        if(_n_protons == 0) throw std::runtime_error("Cannot create Nucleus with atomic number 0");
                        else if(_atomic_mass <= 0) throw std::runtime_error("Cannot create Nucleus with 0 or negative atomic mass");
                    }

            const std::string getName() const {return _name;}
            //! Get number of neutrons @f$N@f$
            const int N() const {return _n_neutrons;}
            //! Get atomic mass number @f$A@f$
            const int A() const {return _n_neutrons+_n_protons;}
            //! Get number of protons/atomic number @f$Z@f$
            const int Z() const {return _n_protons;}
            //! Get atomic mass
            const double M() const {return _atomic_mass;}
            //! Get the mass defect for the nucleus
            const double mass_defect() const;

            Nucleus& operator= (const Nucleus& other);

            friend std::ostream& operator<< (std::ostream& o, const Nucleus& n)
            {
                o << n.getName() << "[Z:  " << n.Z() << ", A: " << n.M() << "]";

                return o;
            }
    };

    /*! @brief  Isotope Subclass
	@details    Class representing isotopes which inherits from the Nucleus class
	@version    0.1.0
	@author     Kristian Zarebski
	@date 	    last modified 2019-08-27
	@copyright  MIT License
        */
    class Isotope : public Nucleus
    {
        private:
            const double _half_life = -1;
        public:
            /*! Construct an isotope for a given pre-defined nucleus
            @param n Nucleus for which the isotope shares the same atomic number @f$ Z@f$
            @param half_life The half-life for the given isotope @f$\lambda@f$
            @returns Isotope of Nucleus n
            */
            Isotope(const Nucleus& n, const int n_neutrons, const double half_life) :
                Nucleus(n.getName()+"-"+std::to_string(n_neutrons),
                        n.Z(), n.M()+(n_neutrons-n.N())),
                _half_life(half_life)
            {
            };
            const double getHalfLife() const {return _half_life;}
    };

    /*! Returns the binding energy per nucleon for the given nucleus
    calculated using the semi-empirical mass formula:@n @f$ \frac{\mathrm{BE}}{A\cdot MeV} = a_v - \frac{a_s}{A^{1/3}} - a_c\frac{Z^2}{A^{4/3}}-a_a\frac{(N-Z)^2}{A^{2}} \pm \frac{a_p}{A^{3/2}} @f$
    @cite Harsha:2017qym 
    @param n  Nucleus on which to perform calculation */
    const double getBindingEnergyPerNucleon(const Nucleus* n);
    /*! Nuclei decay - Get the fraction of isotopes at time @f$t@f$
    @n @f$ \frac{N(t)}{N_0} = e^{-t/\lambda}@f$
    @param i Isotope to decay in time @f$t@f$
    @param t Time @f$t@f$in seconds
    */
    const double fracIsotopesAt(const Isotope* i, const double t);
}

#endif
