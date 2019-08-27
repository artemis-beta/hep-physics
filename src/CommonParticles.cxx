//==============================================//
//    Particles Obtained from the PDG Listing   //
//    https://pdg.lbl.gov                       //
//                                              //
//    Last updated for 2017                     //
//==============================================//

#include "CommonParticles.hxx"

//================= Leptons ====================//

 const PHYS::Particle PHYS::Particles::e = PHYS::Particle("e", "-", PHYS::Constants::m_e, 3E36*PHYS::Units::sec);

 const PHYS::Particle PHYS::Particles::mu = PHYS::Particle("mu", "-", 105.6583745*PHYS::Units::MeV, 2.1969811E-6*PHYS::Units::sec);

 const PHYS::Particle PHYS::Particles::tau = PHYS::Particle("tau", "-", 1776.82*PHYS::Units::MeV, 2.90610E-13*PHYS::Units::sec);

 const PHYS::Particle PHYS::Particles::nu_e = PHYS::Particle("nu_e", "", 1E-6*PHYS::Units::MeV, -1);

 const PHYS::Particle PHYS::Particles::nu_mu = PHYS::Particle("nu_mu", "", 1E-6*PHYS::Units::MeV, -1);

 const PHYS::Particle PHYS::Particles::nu_tau = PHYS::Particle("nu_tau", "", 1E-6*PHYS::Units::MeV, -1);

//=============== Strange Mesons================//

 const PHYS::Particle PHYS::Particles::Kplus = PHYS::Particle("K", "+", 493.677*PHYS::Units::MeV, 1.2380E-8);

 const PHYS::Particle PHYS::Particles::phi_1020 = PHYS::Particle("phi", "", 999, 999);

//=========== Light Unflavoured Mesons==========//

 const PHYS::Particle PHYS::Particles::Piplus = PHYS::Particle("pi", "+", 139.57061*PHYS::Units::MeV, 2.6033E-8*PHYS::Units::sec);

 const PHYS::Particle PHYS::Particles::Pi0 = PHYS::Particle("pi", "0", 134.9770*PHYS::Units::MeV, 8.52E-17*PHYS::Units::sec);

//================ B hadrons ===================//

 const PHYS::Particle PHYS::Particles::Bc = PHYS::Particle("Bc", "+", 999, 999);
