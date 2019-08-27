#include "Units.hxx"
#include "Constants.hxx"


const extern double HEP::Units::cd = 1.;

const extern double HEP::Units::m = 1.;
const extern double HEP::Units::mm = 1E-3*m;
const extern double HEP::Units::nm = 1E-9*m;
const extern double HEP::Units::km = 1E3*m;
const extern double HEP::Units::cm = 1E-2*m;
const extern double HEP::Units::angstrom = 1E-10*m;
const extern double HEP::Units::mile = 1.609344E3*m;
const extern double HEP::Units::yd = 0.9144*m;
const extern double HEP::Units::AU = 1.495979E12*m;
const extern double HEP::Units::pc = 3.08567758149E16*m;
const extern double HEP::Units::inch = 0.0254*m;

const extern double HEP::Units::kg  = 1.;
const extern double HEP::Units::t = 1E3*kg;

const extern double HEP::Units::sec = 1.;
const extern double HEP::Units::ms = 1E-3*sec;
const extern double HEP::Units::ns = 1E-9*sec;
const extern double HEP::Units::ps = 1E-12*sec;

const extern double HEP::Units::J = 1.;
const extern double HEP::Units::eV = HEP::Constants::e*J;
const extern double HEP::Units::keV = 1E3*eV;
const extern double HEP::Units::MeV = 1E6*eV;
const extern double HEP::Units::GeV = 1E9*eV;
const extern double HEP::Units::TeV = 1E12*eV;
const extern double HEP::Units::erg = 1E-7*J;

const extern double HEP::Units::b = 1E-28*m*m;
const extern double HEP::Units::mb = 1E-3*b;
const extern double HEP::Units::nb = 1E-9*b;
const extern double HEP::Units::pb = 1E-12*b;
const extern double HEP::Units::fb = 1E-15*b;

const extern double HEP::Units::inv_pb = 1./pb;
const extern double HEP::Units::inv_fb = 1./fb;

const extern double HEP::Units::N = 1.*kg*pow(m,-2);
const extern double HEP::Units::dyne = 1E-5*N;
const extern double HEP::Units::kN = 1E3*N;

const extern double HEP::Units::A = 1.;
const extern double HEP::Units::C = 1.*A*sec;
const extern double HEP::Units::V = 1.*J*pow(C,-1);
const extern double HEP::Units::F = 1.*C*pow(V,-1);
const extern double HEP::Units::W = J/sec;
const extern double HEP::Units::Ohms = V/A;
const extern double HEP::Units::S = A/V;
const extern double HEP::Units::Wb = V*sec;
const extern double HEP::Units::H = Wb/A;
const extern double HEP::Units::esu = pow(2.99792458E-9, -1)*C;

const extern double HEP::Units::K = 1.;
const extern double HEP::Units::Celsius = -273.15;
const extern double HEP::Units::Fahrenheit = 33.8*Celsius;

const extern double HEP::Units::T = Wb*pow(m, -2);
const extern double HEP::Units::G = 1E-4*T;

const extern double HEP::Units::Pa = 1.*N*pow(m, -2);
const extern double HEP::Units::atm = 1.01325E5*Pa;
const extern double HEP::Units::Torr = pow(760.,-1)*atm;

const extern double HEP::Units::rad = 1.;
const extern double HEP::Units::deg = rad*180/HEP::Constants::pi;
const extern double HEP::Units::sr = 1.;

const extern double HEP::Units::Hz = 1./sec;

const extern double HEP::Units::lm = cd*sr;
const extern double HEP::Units::lx = lm*pow(m, -2);

const extern double HEP::Units::Bq = 1.;

const extern double HEP::Units::Gy = J*pow(kg, -1);
const extern double HEP::Units::Sv = J*pow(kg, -1);

const extern double HEP::Units::kat = 1.;