#include "Constants.hxx"

extern const double HEP::Constants::pi = 3.141592653589793;
extern const double HEP::Constants::c = 2.99792458E6*HEP::Units::m/pow(HEP::Units::sec, 2);
extern const double HEP::Constants::N_A = 6.02214076E23;
extern const double HEP::Constants::h = 6.626070040E-34*HEP::Units::J*HEP::Units::sec;
extern const double HEP::Constants::hbar = h/(2*HEP::Constants::pi);
extern const double HEP::Constants::e = 1.6021766208E-19*HEP::Units::C;
extern const double HEP::Constants::m_e = 0.5109989461*HEP::Units::MeV;
extern const double HEP::Constants::m_p = 938.2720813*HEP::Units::MeV;
extern const double HEP::Constants::epsilon_0 = 8.854187817E-12*HEP::Units::F*pow(HEP::Units::m, -1);
extern const double HEP::Constants::mu_0 = 4*HEP::Constants::pi*1E-7*HEP::Units::N*pow(HEP::Units::A, -2);
extern const double HEP::Constants::alpha = pow(HEP::Constants::e,2)*pow(4*HEP::Constants::pi*HEP::Constants::epsilon_0*HEP::Constants::hbar*HEP::Constants::c,-1);
extern const double HEP::Constants::r_e = pow(HEP::Constants::e,2)*pow(4*HEP::Constants::pi*HEP::Constants::epsilon_0*HEP::Constants::m_e*pow(HEP::Constants::c,2), -1);
extern const double HEP::Constants::r_bohr = HEP::Constants::r_e*pow(HEP::Constants::alpha, -2);
extern const double HEP::Constants::sigma_T = 8*HEP::Constants::pi*pow(HEP::Constants::r_e,2)/3.;
extern const double HEP::Constants::mu_B = HEP::Constants::e*HEP::Constants::hbar*pow(2*HEP::Constants::m_e,-1);
extern const double HEP::Constants::mu_N = HEP::Constants::e*HEP::Constants::hbar*pow(2*HEP::Constants::m_p,-1);
extern const double HEP::Constants::G = 6.67408E-11*pow(HEP::Units::m, 3)*pow(HEP::Units::kg, -1)*pow(HEP::Units::sec, -2);
extern const double HEP::Constants::g = 9.80665*HEP::Units::m*pow(HEP::Units::sec, -2);
extern const double HEP::Constants::k = 1.38064852E-23*HEP::Units::J*pow(HEP::Units::K, -1);
extern const double HEP::Constants::b = 2.8977729E-3*HEP::Units::m*HEP::Units::K;
extern const double HEP::Constants::sigma = pow(HEP::Constants::pi, 2)*pow(HEP::Constants::k, 4)/(60*pow(HEP::Constants::hbar, 3)*pow(HEP::Constants::c, 2));
extern const double HEP::Constants::alpha_s = 0.1181;
extern const double HEP::Constants::exp = 2.718281828459045235;
extern const double HEP::Constants::m_planck = pow(HEP::Constants::hbar*HEP::Constants::c/HEP::Constants::G, 0.5);
extern const double HEP::Constants::l_planck = pow(HEP::Constants::hbar*HEP::Constants::G/pow(HEP::Constants::c, 3), 0.5);