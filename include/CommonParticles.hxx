#ifndef __COMMONPARTICLES__
#define __COMMONPARTICLES__

#include "Particle.hxx"

/*! @namespace HEP
    The HEP namespace contains all currently accepted particles within the standard model
    and beyond. The masses and data are taken from the Particle Data Group listings @cite PDGlist.
    @warning It is recommend you do not use the namespace within the script as there is
    a high probability of accidental overwriting. Instead use the particles as HEP::particle

    @todo Finish all particle definitions
    
    @author K. Zarebski

    @license MIT License

    @date last modified 2019-08-26
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
extern const Particle gamma;

//! Gluon, @f$g@f$
extern const Particle g;

//! W Boson, @f$W^{+}@f$
extern const Particle W;

//! Z Boson, @f$Z^0@f$
extern const Particle Z;

//! Higgs Boson, @f$H@f$
extern const Particle H;

//================= Leptons ====================//

//! Electron, @f$e^-@f$
 extern const Particle e;

//! Muon, @f$\mu^-@f$
 extern const Particle mu;

//! Tau, @f$\tau^-@f$
 extern const Particle tau;

//! Electron Neutrino, @f$ \nu_{e} @f$
 extern const Particle nu_e;

//! Muon Neutrino, @f$ \nu_{ \mu } @f$
 extern const Particle nu_mu;

//! Tau Neutrino, @f$ \nu_{ \tau } @f$
 extern const Particle nu_tau;

//=============== Strange Mesons================//

//! Charged Kaon, @f$ K^{+} @f$
 extern const Particle Kplus;

//! Phi 1020,  @f$ \phi(1020) @f$
 extern const Particle phi_1020;

//=========== Light Unflavoured Mesons==========//

//! Eta meson, @f$ \eta @f$
 extern const Particle eta;

//! Charged Pion, @f$ \pi^{+} @f$
 extern const Particle Piplus;

//! Neutral Pion, @f$ \pi^{0} @f$
 extern const Particle Pi0;

//=============== Charmed Mesons================//

//! Charged D meson, @f$ D^{+} @f$
 extern const Particle Dplus;

//! Neutral D meson, @f$ D^{0} @f$
 extern const Particle D0;

//=========== Charmed Strange Mesons ===========//
 
//! Neutral D strange meson, @f$ D_s @f$
 extern const Particle Ds;
 
//================ Bottom Mesons ===============//

//! Charge B meson, @f$ B^{+} @f$
 extern const Particle Bplus;

//! Neutral B meson, @f$ B^{0} @f$
 extern const Particle B0;

//============= Bottom Strange Mesons ==========//

//! Neutral B strange meson, @f$ B_s @f$
 extern const Particle Bs;

//============= Charmed Bottom Mesons ==========//

//! Charmed B meson, @f$ B_c @f$
 extern const Particle Bc;

//================= N Baryons ==================//

//! Proton, @f$ p @f$
 extern const Particle p;

//! Neutron, @f$ n @f$
 extern const Particle n;

//============== Lambda Baryons ================//


//! Lambda baryon, @f$ \Lambda @f$
 extern const Particle Lambda;

//! Lambda b baryon, @f$ \Lambda_{b}^{0} @f$
 extern const Particle Lambdab0;

//============== Sigma Baryons =================//

//! Neutral Sigma baryon, @f$ \Sigma^{0} @f$
 extern const Particle Sigma;

//! Charged Sigma baryon, @f$ \Sigma^{+} @f$
 extern const Particle Sigmaplus;

//=============== Xi Barysons ==================//

//! Neutral Xi baryon, @f$ \Xi^{0} @f$
 extern const Particle Xi0;

//! Charged Xi baryon, @f$ \Xi^{+} @f$
 extern const Particle Ximinus;

//============== Omega Baryons =================//

//! Omega baryon, @f$ \Omega @f$
 extern const Particle Omega;

//============= Charmed Baryons ================//

//! Lambda c baryon, @f$ \Lambda_c @f$
 extern const Particle Lambdac;

};

#endif
