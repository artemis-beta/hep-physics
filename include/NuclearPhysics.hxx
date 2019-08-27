#ifndef __NUCLEAR_HXX__
#define __NUCLEAR_HXX__

#include <string>
#include <cmath>

#include "Constants.hxx"

namespace HEP
{
    class Nucleus
    {
        private:
            const std::string name_;
            const int n_protons_;
            const int n_neutrons_;
            const double atomic_mass_;
        public:
            Nucleus(const std::string name, const int atomic_number, const double atomic_mass) :
                    name_(name), 
                    n_protons_(atomic_number),
                    n_neutrons_(round(atomic_mass)),
                    atomic_mass_(atomic_mass) {};

            //! Get number of neutrons @f$N@f$
            const int N() const {return n_neutrons_;}
            //! Get atomic mass number @f$A@f$
            const int A() const {return n_neutrons_+n_protons_;}
            //! Get number of protons/atomic number @f$Z@f$
            const int Z() const {return n_protons_;}
            //! Get the mass defect for the nucleus
            const double mass_defect() const;
    };
    const double getBindingEnergyPerNucleon(const Nucleus* n);
}

#endif