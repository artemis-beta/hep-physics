//==============================================//
//    Particles Obtained from the PDG Listing   //
//    https://pdg.lbl.gov                       //
//                                              //
//    Last updated for 2017                     //
//==============================================//

#include "CommonParticles.hxx"

//================= Leptons ====================//

 const HEP::Particle HEP::Particles::e = HEP::Particle("e", "-", HEP::Constants::m_e, 3E36*HEP::Units::sec);

 const HEP::Particle HEP::Particles::mu = HEP::Particle("mu", "-", 105.6583745*HEP::Units::MeV, 2.1969811E-6*HEP::Units::sec);

 const HEP::Particle HEP::Particles::tau = HEP::Particle("tau", "-", 1776.82*HEP::Units::MeV, 2.90610E-13*HEP::Units::sec);

 const HEP::Particle HEP::Particles::nu_e = HEP::Particle("nu_e", "", 1E-6*HEP::Units::MeV, -1);

 const HEP::Particle HEP::Particles::nu_mu = HEP::Particle("nu_mu", "", 1E-6*HEP::Units::MeV, -1);

 const HEP::Particle HEP::Particles::nu_tau = HEP::Particle("nu_tau", "", 1E-6*HEP::Units::MeV, -1);

//=============== Strange Mesons================//

 const HEP::Particle HEP::Particles::Kplus = HEP::Particle("K", "+", 493.677*HEP::Units::MeV, 1.2380E-8);

 const HEP::Particle HEP::Particles::phi_1020 = HEP::Particle("phi", "", 999, 999);

//=========== Light Unflavoured Mesons==========//

 const HEP::Particle HEP::Particles::Piplus = HEP::Particle("pi", "+", 139.57061*HEP::Units::MeV, 2.6033E-8*HEP::Units::sec);

 const HEP::Particle HEP::Particles::Pi0 = HEP::Particle("pi", "0", 134.9770*HEP::Units::MeV, 8.52E-17*HEP::Units::sec);

//================ B hadrons ===================//

 const HEP::Particle HEP::Particles::Bc = HEP::Particle("Bc", "+", 999, 999);
