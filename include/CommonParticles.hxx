#ifndef __COMMONPARTICLES__
#define __COMMONPARTICLES__

#include "Particle.hxx"

/*! @namespace HEP
    The HEP namespace contains all currently accepted particles within the standard model
    and beyond. The masses and data are taken from the Particle Data Group listings @cite PDGlist.
    @warning It is recommend you do not use the namespace within the script as there is
    a high probability of accidental overwriting. Instead use the particles as HEP::particle
    @todo Finish all particle definitions
*/

namespace HEP
{

//==============================================//
//    Particles Obtained from the PDG Listing   //
//    https://pdg.lbl.gov                       //
//                                              //
//    Last updated for 2017                     //
//==============================================//

//=========== Gauge & Higgs Bosons =============//

//! Photon, @f$\gamma@f$
extern Particle gamma;

//! Gluon, @f$g@f$
extern Particle g;

//! W Boson, @f$W^{+}@f$
extern Particle W;

//! Z Boson, @f$Z^0@f$
extern Particle Z;

//! Higgs Boson, @f$H@f$
extern Particle H;

//================= Leptons ====================//

//! Electron, @f$e^-@f$
 extern Particle e;

//! Muon, @f$\mu^-@f$
 extern Particle mu;

//! Tau, @f$\tau^-@f$
 extern Particle tau;

//! Electron Neutrino, @f$ \nu_{e} @f$
 extern Particle nu_e;

//! Muon Neutrino, @f$ \nu_{ \mu } @f$
 extern Particle nu_mu;

//! Tau Neutrino, @f$ \nu_{ \tau } @f$
 extern Particle nu_tau;

//=============== Strange Mesons================//

//! Charged Kaon, @f$ K^{+} @f$
 extern Particle Kplus;

//! Phi 1020,  @f$ \phi(1020) @f$
 extern Particle phi_1020;

//=========== Light Unflavoured Mesons==========//

//! Eta meson, @f$ \eta @f$
 extern Particle eta;

//! Charged Pion, @f$ \pi^{+} @f$
 extern Particle Piplus;

//! Neutral Pion, @f$ \pi^{0} @f$
 extern Particle Pi0;

//=============== Charmed Mesons================//

//! Charged D meson, @f$ D^{+} @f$
 extern Particle Dplus;

//! Neutral D meson, @f$ D^{0} @f$
 extern Particle D0;

//=========== Charmed Strange Mesons ===========//
 
//! Neutral D strange meson, @f$ D_s @f$
 extern Particle Ds;
 
//================ Bottom Mesons ===============//

//! Charge B meson, @f$ B^{+} @f$
 extern Particle Bplus;

//! Neutral B meson, @f$ B^{0} @f$
 extern Particle B0;

//============= Bottom Strange Mesons ==========//

//! Neutral B strange meson, @f$ B_s @f$
 extern Particle Bs;

//============= Charmed Bottom Mesons ==========//

//! Charmed B meson, @f$ B_c @f$
 extern Particle Bc;

//================= N Baryons ==================//

//! Proton, @f$ p @f$
 extern Particle p;

//! Neutron, @f$ n @f$
 extern Particle n;

//============== Lambda Baryons ================//


//! Lambda baryon, @f$ \Lambda @f$
 extern Particle Lambda;

//! Lambda b baryon, @f$ \Lambda_{b}^{0} @f$
 extern Particle Lambdab0;

//============== Sigma Baryons =================//

//! Neutral Sigma baryon, @f$ \Sigma^{0} @f$
 extern Particle Sigma;

//! Charged Sigma baryon, @f$ \Sigma^{+} @f$
 extern Particle Sigmaplus;

//=============== Xi Barysons ==================//

//! Neutral Xi baryon, @f$ \Xi^{0} @f$
 extern Particle Xi0;

//! Charged Xi baryon, @f$ \Xi^{+} @f$
 extern Particle Ximinus;

//============== Omega Baryons =================//

//! Omega baryon, @f$ \Omega @f$
 extern Particle Omega;

//============= Charmed Baryons ================//

//! Lambda c baryon, @f$ \Lambda_c @f$
 extern Particle Lambdac;

};

#endif
