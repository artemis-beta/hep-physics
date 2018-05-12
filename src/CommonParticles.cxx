#include "CommonParticles.hxx"

Particle e()
{
	return Particle("e", "-", 0.5109989461, 3E36);
}

Particle mu()
{
	return Particle("mu", "-", 105.6583745, 2.1969811E-6);
}

Particle tau()
{
	return Particle("tau", "-", 1776.82, 2.90610E-13);
}

Particle nu_e()
{
	return Particle("nu_e", "", 1E-6, -1);
}	

Particle nu_mu()
{
	return Particle("nu_mu", "", 1E-6, -1);
}	

Particle nu_tau()
{
	return Particle("nu_tau", "", 1E-6, -1);
}	

//=========== Light Unflavoured Mesons==========//

Particle Piplus()
{
	return Particle("Pi", "+", 139.57061, 2.6033E-8);
}

Particle Pi0()
{
	return Particle("Pi", "0", 134.9770, 8.52E-17);
}

//=============== Strange Mesons================//

Particle Kplus()
{
	return Particle("K", "+", 493.677, 1.2380E-8);
}

