#include "Constants.hxx"

extern const double PHYS::Constants::pi = 3.141592653589793;
extern const double PHYS::Constants::c = 2.99792458E6*PHYS::Units::m/pow(PHYS::Units::sec, 2);
extern const double PHYS::Constants::N_A = 6.02214076E23;
extern const double PHYS::Constants::h = 6.626070040E-34*PHYS::Units::J*PHYS::Units::sec;
extern const double PHYS::Constants::hbar = h/(2*PHYS::Constants::pi);
extern const double PHYS::Constants::e = 1.6021766208E-19*PHYS::Units::C;
extern const double PHYS::Constants::m_e = 0.5109989461*PHYS::Units::MeV;
extern const double PHYS::Constants::m_p = 938.2720813*PHYS::Units::MeV;
extern const double PHYS::Constants::epsilon_0 = 8.854187817E-12*PHYS::Units::F*pow(PHYS::Units::m, -1);
extern const double PHYS::Constants::mu_0 = 4*PHYS::Constants::pi*1E-7*PHYS::Units::N*pow(PHYS::Units::A, -2);
extern const double PHYS::Constants::alpha = pow(PHYS::Constants::e,2)*pow(4*PHYS::Constants::pi*PHYS::Constants::epsilon_0*PHYS::Constants::hbar*PHYS::Constants::c,-1);
extern const double PHYS::Constants::r_e = pow(PHYS::Constants::e,2)*pow(4*PHYS::Constants::pi*PHYS::Constants::epsilon_0*PHYS::Constants::m_e*pow(PHYS::Constants::c,2), -1);
extern const double PHYS::Constants::r_bohr = PHYS::Constants::r_e*pow(PHYS::Constants::alpha, -2);
extern const double PHYS::Constants::sigma_T = 8*PHYS::Constants::pi*pow(PHYS::Constants::r_e,2)/3.;
extern const double PHYS::Constants::mu_B = PHYS::Constants::e*PHYS::Constants::hbar*pow(2*PHYS::Constants::m_e,-1);
extern const double PHYS::Constants::mu_N = PHYS::Constants::e*PHYS::Constants::hbar*pow(2*PHYS::Constants::m_p,-1);
extern const double PHYS::Constants::G = 6.67408E-11*pow(PHYS::Units::m, 3)*pow(PHYS::Units::kg, -1)*pow(PHYS::Units::sec, -2);
extern const double PHYS::Constants::g = 9.80665*PHYS::Units::m*pow(PHYS::Units::sec, -2);
extern const double PHYS::Constants::k = 1.38064852E-23*PHYS::Units::J*pow(PHYS::Units::K, -1);
extern const double PHYS::Constants::b = 2.8977729E-3*PHYS::Units::m*PHYS::Units::K;
extern const double PHYS::Constants::sigma = pow(PHYS::Constants::pi, 2)*pow(PHYS::Constants::k, 4)/(60*pow(PHYS::Constants::hbar, 3)*pow(PHYS::Constants::c, 2));
extern const double PHYS::Constants::alpha_s = 0.1181;
extern const double PHYS::Constants::exp = 2.718281828459045235;
extern const double PHYS::Constants::m_planck = pow(PHYS::Constants::hbar*PHYS::Constants::c/PHYS::Constants::G, 0.5);
extern const double PHYS::Constants::l_planck = pow(PHYS::Constants::hbar*PHYS::Constants::G/pow(PHYS::Constants::c, 3), 0.5);
extern const double PHYS::Constants::u = 1.66053906660E-27*PHYS::Units::kg;
extern const double PHYS::Constants::R = 8.31411*PHYS::Units::J*pow(PHYS::Units::K*PHYS::Units::mol, -1);
    
