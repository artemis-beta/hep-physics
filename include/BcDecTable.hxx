#ifndef __BCDECTABLE__
#define __BCDECTABLE__

#include "CommonParticles.hxx"
#include "DecayTable.hxx"

const HEP::DecayTable gen_BcDecays()
{
    HEP::DecayTable _tmp(HEP::Particles::Bc);

    std::vector<HEP::Particle> _d = {HEP::Particles::phi_1020, HEP::Particles::Kplus};    

    HEP::Decay _dec = HEP::Decay(_d, 1E-3);

    _tmp.addDecay(_dec);

    return _tmp;

} 

namespace HEP
{
    //! HEP::DecayTable of all decays of the @f$ B_c @f$ meson. The @c gen_BcDecays function generates all the relevant channels
    extern const DecayTable BcDecays = gen_BcDecays();
}

#endif
