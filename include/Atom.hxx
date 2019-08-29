#ifndef __ATOM_HXX__
#define __ATOM_HXX__

#include "NuclearPhysics.hxx"
#include <iostream>

namespace PHYS
{
    /*! @brief  Atom Class
	@details    Sister class of Nucleus representing an atom or ion with electrons
	@version    0.1.0
	@author     Kristian Zarebski
	@date 	    last modified 2019-08-28
	@copyright  MIT License
    */
    class Atom
    {
        private:
            PHYS::Nucleus _nucleus;
            int _n_electrons;
            bool _is_ion = false;
        public:
            /*! Define a new atom using a given nucleus. The number of electrons will be
            set to be equal to the number of protons of the nucleus
            @param n Nucleus for the defined atom
            */
            Atom(const PHYS::Nucleus& n) :
                _nucleus(n),
                _n_electrons(n.Z()) 
                {
                    if(n.Z() == 0) throw std::runtime_error("Cannot create Atom from Nucleus with atomic number 0");
                }
            /*! Add/Remove electrons to the atom making it an ion
            @param n_electrons Can be positive or negative integer for adding/removing electrons
            @returns void*/
            void addElectrons(const int n_electrons);
            /*! Returns whether given atom is an ion
            @returns bool*/
            const bool isIon() const {return _is_ion;}
            const Nucleus getNucleus() const {return _nucleus;};
            Atom& operator= (const Atom& other);
            const double A() const {return _nucleus.A();}
            const double Z() const {return _nucleus.Z();}
            const double M() const {return _nucleus.M();}

            friend std::ostream& operator<< (std::ostream& o, const Atom& a)
            {   
                o << a.getNucleus();

                if(a.isIon())
                {
                    o << abs(a._n_electrons - a.Z());
                    std::string sign = (a._n_electrons - a.Z() > 0) ? "-" : "+";
                    o << sign;
                }

                return o;
            }

    };

    bool operator< (Atom const & a, Atom const & b);
    bool operator> (Atom const & a, Atom const & b);
    bool operator== (Atom const & a, Atom const & b);

    typedef Atom Ion;
}

#endif