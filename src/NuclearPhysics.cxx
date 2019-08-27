#include "NuclearPhysics.hxx"

const double PHYS::Nucleus::mass_defect() const
{
    const double m_p = 1.007276;
    const double m_n = 1.008665;

    return (m_p*_n_protons+m_n*_n_neutrons-_atomic_mass)*PHYS::Constants::u;
}

const double PHYS::getBindingEnergyPerNucleon(const Nucleus* n)
{
    double const a_v = 15.7827, a_s = 17.9042, a_c = 0.724040, a_a = 23.7193, a_p = 11;

    double _tmp = a_v - a_s/pow(n->A(), -1/3.) - a_c*pow(n->Z(), 2)*pow(n->A(), -4/3.);
    _tmp -= a_a*pow(n->N()-n->Z(), 2)*pow(n->A(), 2);

    if(n->N() % 2 != 0 && n->Z() % 2 != 0){_tmp -= a_p*pow(n->A(), -3/2.);}

    else if(n->N() % 2 == 0 && n->Z() % 2 == 0){_tmp += a_p*pow(n->A(), -3/2.);}

    return _tmp;
}

const double PHYS::fracIsotopesAt(const Isotope* i, const double time)
{
    return exp(-time/i->getHalfLife());
}