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

const PHYS::LorentzVector PHYS::LorentzVector::operator+ (const PHYS::LorentzVector& other) const
{
    return PHYS::LorentzVector(x0+other.x0, x1+other.x1, x2+other.x2, x3+other.x3);
}

