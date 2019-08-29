#include "Vector.hxx"

const double PHYS::Vector::operator[] (const int index) const
{
    switch(index)
    {
        case 0:
            return _x1;
            break;
        case 1:
            return _x2;
            break;
        case 2:
            return _x3;
            break;
        default:
            throw std::runtime_error("Invalid Vector Index");
    }
}

const PHYS::Vector PHYS::Vector::operator+ (const PHYS::Vector& other) const
{
    PHYS::Vector _tmp = PHYS::Vector(_x1+other._x1, 
                                     _x2+other._x2,
                                     _x3+other._x3);
    
    return _tmp;
}

const PHYS::Vector PHYS::Vector::operator- (const PHYS::Vector& other) const
{
    PHYS::Vector _tmp = PHYS::Vector(_x1-other._x1, 
                                     _x2-other._x2,
                                     _x3-other._x3);
    
    return _tmp;
}

const bool PHYS::Vector::operator== (const PHYS::Vector& other) const
{
    return _x1 == other._x1 && _x2 == other._x2 && _x3 == other._x3;
}

const double PHYS::Cartesian::magnitude() const
{
    return pow(pow((*this)[0], 2)+pow((*this)[1], 2)+pow((*this)[2], 2), 0.5);
}

const PHYS::Vector PHYS::Vector::operator+= (const PHYS::Vector& other) const
{
    PHYS::Vector _tmp = *this;
    return _tmp + other;
}

const PHYS::Vector PHYS::Vector::operator= (const PHYS::Vector& other) const
{
    return other;
}

const PHYS::Vector PHYS::Vector::operator/ (const double& other) const
{
    return pow(other,-1)*(*this);
}

const PHYS::Cartesian PHYS::Cartesian::operator- (const PHYS::Cartesian& other) const
{
    return (Cartesian)(Vector(*this)-Vector(other));
}

const PHYS::Cartesian PHYS::Cartesian::operator+ (const PHYS::Cartesian& other) const
{
    return (Cartesian)(Vector(*this)+Vector(other));
}

const PHYS::Spherical PHYS::Cartesian::inSphericalPolar() const
{
    const double r = this->magnitude();
    const double theta = acos((*this)[0]/r);
    const double phi = atan((*this)[1]/(*this)[0]);

    return PHYS::Spherical(r, theta, phi);
}

const PHYS::Cartesian PHYS::Spherical::inCartesian() const
{
    const double x = (*this)[0]*sin((*this)[1])*cos((*this)[2]);
    const double y = (*this)[0]*sin((*this)[1])*sin((*this)[2]);
    const double z = (*this)[0]*cos((*this)[1]);

    return PHYS::Cartesian(x, y, z);
}

const double PHYS::Spherical::magnitude() const
{
    return abs((*this)[0]);
}