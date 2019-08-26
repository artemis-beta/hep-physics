//==============================================//
//    Particles Obtained from the PDG Listing   //
//    https://pdg.lbl.gov                       //
//                                              //
//    Last updated for 2017                     //
//==============================================//

#include "CommonParticles.hxx"

using namespace HEP;

//================= Leptons ====================//

 Particle HEP::e = Particle("e", "-", 0.5109989461, 3E36);

 Particle HEP::mu = Particle("mu", "-", 105.6583745, 2.1969811E-6);

 Particle HEP::tau = Particle("tau", "-", 1776.82, 2.90610E-13);

 Particle HEP::nu_e = Particle("nu_e", "", 1E-6, -1);

 Particle HEP::nu_mu = Particle("nu_mu", "", 1E-6, -1);

 Particle HEP::nu_tau = Particle("nu_tau", "", 1E-6, -1);

//=============== Strange Mesons================//

 Particle HEP::Kplus = Particle("K", "+", 493.677, 1.2380E-8);

 Particle HEP::phi_1020 = Particle("phi", "", 999, 999);

//=========== Light Unflavoured Mesons==========//

 Particle HEP::Piplus = Particle("pi", "+", 139.57061, 2.6033E-8);

 Particle HEP::Pi0 = Particle("pi", "0", 134.9770, 8.52E-17);

//================ B hadrons ===================//

 Particle HEP::Bc = Particle("Bc", "+", 999, 999);
