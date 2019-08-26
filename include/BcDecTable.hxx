#ifndef __BCDECTABLE__
#define __BCDECTABLE__

#include "CommonParticles.hxx"
#include "DecayTable.hxx"

using namespace HEP;


const DecayTable gen_BcDecays()
{
    DecayTable _tmp(Bc);

    std::vector<Particle> _d = {phi_1020, Kplus};    

    Decay _dec = Decay(_d, 1E-3);

    _tmp.addDecay(_dec);

    return _tmp;

} 

namespace HEP
{
    //! DecayTable of all decays of the @f$ B_c @f$ meson. The @c gen_BcDecays function generates all the relevant channels
    extern const DecayTable BcDecays = gen_BcDecays();
}

#endif
