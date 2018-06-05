#include "HEPLorentzVector.hxx"

HEPLorentzVector::HEPLorentzVector(double x0_, double x1_, double x2_, double x3_)
{
    x0 = x0_;
    x1 = x1_;
    x2 = x2_;
    x3 = x3_;
}

double& HEPLorentzVector::operator[] (size_t i)
{  
    switch (i)
    {
        case 0: return x0;
        case 1: return x1;
        case 2: return x2;
        default: return x3;
    }
}

std::ostream& operator<<(std::ostream& os, const HEPLorentzVector& lv)
{
    os << "<" << lv.x0 << ",";
    os << lv.x1 << ",";
    os << lv.x2 << ",";
    os << lv.x3 << ",";
    os << "HEPLorentzVector('double')>" << std::endl;

    return os;
}

