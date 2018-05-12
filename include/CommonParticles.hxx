#ifndef __COMMONPARTICLES__
#define __COMMONPARTICLES__

#include "Particle.hxx"

class Particle;

//==============================================//
//    Particles Obtained from the PDG Listing   //
//    https://pdg.lbl.gov                       //
//                                              //
//    Last updated for 2017                     //
//==============================================//

//================= Leptons ====================//

Particle e();

Particle mu();

Particle tau();

Particle nu_e();

Particle nu_mu();

Particle nu_tau();

//=========== Light Unflavoured Mesons==========//

Particle Piplus();

Particle Pi0();

//=============== Strange Mesons================//

Particle Kplus();

#endif
