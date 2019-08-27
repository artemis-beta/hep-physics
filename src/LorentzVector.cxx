#include "LorentzVector.hxx"

PHYS::LorentzVector::LorentzVector(double x0_, double x1_, double x2_, double x3_)
{
    x0 = x0_;
    x1 = x1_;
    x2 = x2_;
    x3 = x3_;
}

const double& PHYS::LorentzVector::operator[] (size_t i)
{  
    switch (i)
    {
        case 0: return x0;
        case 1: return x1;
        case 2: return x2;
        default: return x3;
    }
}

std::ostream& operator<<(std::ostream& os, const PHYS::LorentzVector& lv)
{
    os << "<" << lv[0] << ",";
    os << lv[1] << ",";
    os << lv[2] << ",";
    os << lv[3] << ",";
    os << "LorentzVector('double')>" << std::endl;

    return os;
}

