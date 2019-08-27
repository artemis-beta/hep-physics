#include "NuclearPhysics.hxx"

const double HEP::Nucleus::mass_defect() const
{
    const double m_p = 1.007276;
    const double m_n = 1.008665;

    return (m_p*n_protons_+m_n*n_neutrons_-atomic_mass_)*HEP::Constants::u;
}

const double HEP::getBindingEnergyPerNucleon(const Nucleus* n)
{
    double const a = 14.0, b = 13.0, c = 0.585, d = 19.3, e = 33;

    double _tmp = a - b/pow(n->A(), -1/3.) - c*pow(n->Z(), 2)*pow(n->A(), -4/3.);
    _tmp -= d*pow(n->N()-n->Z(), 2)*pow(n->A(), 2);

    if(n->N() % 2 != 0 && n->Z() % 2 != 0){_tmp -= e*pow(n->A(), -7/4.);}

    else if(n->N() % 2 == 0 && n->Z() % 2 == 0){_tmp += e*pow(n->A(), -7/4.);}

    return _tmp;
}