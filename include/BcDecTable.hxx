#ifndef __BCDECTABLE__
#define __BCDECTABLE__

#include "CommonParticles.hxx"
#include "DecayTable.hxx"

const PHYS::DecayTable gen_BcDecays()
{
    PHYS::DecayTable _tmp(PHYS::Particles::Bc);

    std::vector<PHYS::Particle> _d = {PHYS::Particles::phi_1020, PHYS::Particles::Kplus};    

    PHYS::Decay _dec = PHYS::Decay(_d, 1E-3);

    _tmp.addDecay(_dec);

    return _tmp;

} 

namespace PHYS
{
    //! PHYS::DecayTable of all decays of the @f$ B_c @f$ meson. The @c gen_BcDecays function generates all the relevant channels
    extern const DecayTable BcDecays = gen_BcDecays();
}

#endif
