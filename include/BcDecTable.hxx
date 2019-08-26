#ifndef __BCDECTABLE__
#define __BCDECTABLE__

#include "CommonParticles.hxx"
#include "DecayTable.hxx"

using namespace HEP;


DecayTable BcDecays()
{
    DecayTable _tmp(Bc);

    std::vector<Particle> _d = {phi_1020, Kplus};    

    Decay _dec = Decay(_d, 1E-3);

    _tmp.addDecay(_dec);

    return _tmp;

}    

#endif
