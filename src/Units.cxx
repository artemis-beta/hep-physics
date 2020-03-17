#include "Units.hxx"
#include "Constants.hxx"


const extern double PHYS::Units::cd = 1.;

const extern double PHYS::Units::m = 1.;
const extern double PHYS::Units::mm = 1E-3*m;
const extern double PHYS::Units::nm = 1E-9*m;
const extern double PHYS::Units::km = 1E3*m;
const extern double PHYS::Units::cm = 1E-2*m;
const extern double PHYS::Units::angstrom = 1E-10*m;
const extern double PHYS::Units::mile = 1.609344E3*m;
const extern double PHYS::Units::yd = 0.9144*m;
const extern double PHYS::Units::AU = 1.495979E12*m;
const extern double PHYS::Units::pc = 3.08567758149E16*m;
const extern double PHYS::Units::inch = 0.0254*m;

const extern double PHYS::Units::kg  = 1.;
const extern double PHYS::Units::t = 1E3*kg;
const extern double PHYS::Units::g = 1E-3*kg;

const extern double PHYS::Units::sec = 1.;
const extern double PHYS::Units::min = 60*sec;
const extern double PHYS::Units::hr = 60*min;
const extern double PHYS::Units::day = 24*hr;
const extern double PHYS::Units::yr = 365.25*day;
const extern double PHYS::Units::ms = 1E-3*sec;
const extern double PHYS::Units::ns = 1E-9*sec;
const extern double PHYS::Units::ps = 1E-12*sec;

const extern double PHYS::Units::b = 1E-28*m*m;
const extern double PHYS::Units::mb = 1E-3*b;
const extern double PHYS::Units::nb = 1E-9*b;
const extern double PHYS::Units::pb = 1E-12*b;
const extern double PHYS::Units::fb = 1E-15*b;

const extern double PHYS::Units::inv_pb = 1./pb;
const extern double PHYS::Units::inv_fb = 1./fb;

const extern double PHYS::Units::N = 1.*kg*pow(m,-2);
const extern double PHYS::Units::dyne = 1E-5*N;
const extern double PHYS::Units::kN = 1E3*N;

const extern double PHYS::Units::A = 1.;
const extern double PHYS::Units::C = 1.*A*sec;
const extern double PHYS::Units::V = 1.*J*pow(C,-1);
const extern double PHYS::Units::F = 1.*C*pow(V,-1);
const extern double PHYS::Units::W = J/sec;
const extern double PHYS::Units::Ohms = V/A;
const extern double PHYS::Units::S = A/V;
const extern double PHYS::Units::Wb = V*sec;
const extern double PHYS::Units::H = Wb/A;
const extern double PHYS::Units::esu = pow(2.99792458E-9, -1)*C;

const extern double PHYS::Units::K = 1.;
const extern double PHYS::Units::Celsius(const double& kelvin) {return kelvin+273.15;}
const extern double PHYS::Units::Fahrenheit(const double& kelvin){return 33.8*Celsius(kelvin);}

const extern double PHYS::Units::T = Wb*pow(m, -2);
const extern double PHYS::Units::G = 1E-4*T;

const extern double PHYS::Units::Pa = 1.*N*pow(m, -2);
const extern double PHYS::Units::atm = 1.01325E5*Pa;
const extern double PHYS::Units::Torr = pow(760.,-1)*atm;

const extern double PHYS::Units::rad = 1.;
const extern double PHYS::Units::deg = rad*180/PHYS::Constants::pi;
const extern double PHYS::Units::sr = 1.;

const extern double PHYS::Units::Hz = 1./sec;

const extern double PHYS::Units::lm = cd*sr;
const extern double PHYS::Units::lx = lm*pow(m, -2);

const extern double PHYS::Units::Bq = 1.;

const extern double PHYS::Units::Gy = J*pow(kg, -1);
const extern double PHYS::Units::Sv = J*pow(kg, -1);

const extern double PHYS::Units::kat = 1.;

const extern double PHYS::Units::mol = 1.;


const extern double PHYS::Units::J = 1.;
const extern double PHYS::Units::eV = 1.6021766208E-19*J;
const extern double PHYS::Units::keV = 1E3*eV;
const extern double PHYS::Units::MeV = 1E6*eV;
const extern double PHYS::Units::GeV = 1E9*eV;
const extern double PHYS::Units::TeV = 1E12*eV;
const extern double PHYS::Units::erg = 1E-7*J;