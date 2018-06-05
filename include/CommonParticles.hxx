#ifndef __COMMONPARTICLES__
#define __COMMONPARTICLES__

#include "Particle.hxx"

namespace HEP
{

//==============================================//
//    Particles Obtained from the PDG Listing   //
//    https://pdg.lbl.gov                       //
//                                              //
//    Last updated for 2017                     //
//==============================================//

//=========== Gauge & Higgs Bosons =============//

extern Particle gamma;

extern Particle g;

extern Particle W;

extern Particle Z;

extern Particle H;

//================= Leptons ====================//

 extern Particle e;

 extern Particle mu;

 extern Particle tau;

 extern Particle nu_e;

 extern Particle nu_mu;

 extern Particle nu_tau;

//=============== Strange Mesons================//

 extern Particle Kplus;
 extern Particle phi;

//=========== Light Unflavoured Mesons==========//

 extern Particle eta;
 extern Particle Piplus;
 extern Particle Pi0;

//=============== Charmed Mesons================//

 extern Particle Dplus;
 extern Particle D0;

//=========== Charmed Strange Mesons ===========//
 
 extern Particle Ds;
 
//================ Bottom Mesons ===============//

 extern Particle Bplus;
 extern Particle B0;

//============= Bottom Strange Mesons ==========//

 extern Particle Bs0;

//============= Charmed Bottom Mesons ==========//

 extern Particle Bc;

//================= N Baryons ==================//

 extern Particle p;
 extern Particle n;

//============== Lambda Baryons ================//

 extern Particle Lambda;
 extern Particle Lambdab0;

//============== Sigma Baryons =================//

 extern Particle Sigma;
 extern Particle Sigmaplus;

//=============== Xi Barysons ==================//

 extern Particle Xi0;
 extern Particle Ximinus;

//============== Omega Baryons =================//

 extern Particle Omega;

//============= Charmed Baryons ================//

 extern Particle Lambdac;

};

#endif
