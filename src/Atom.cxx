#include "Atom.hxx"

void PHYS::Atom::addElectrons(const int n_electrons)
{
    _n_electrons += n_electrons;
    if(_nucleus.Z() != _n_electrons) _is_ion = true;
}

bool PHYS::operator< (PHYS::Atom const & a, PHYS::Atom const & b)
{
    return a.getNucleus().Z() < b.getNucleus().Z();
}

bool PHYS::operator> (PHYS::Atom const & a, PHYS::Atom const & b)
{
    return a.getNucleus().Z() > b.getNucleus().Z();
}

bool PHYS::operator== (PHYS::Atom const & a, PHYS::Atom const & b)
{
    return a.getNucleus().Z() == b.getNucleus().Z();
}

PHYS::Atom& PHYS::Atom::operator= (const PHYS::Atom& other)
{
    _nucleus = other._nucleus;
    _n_electrons = other._n_electrons;
    _is_ion = other._is_ion;

    return *this;
}