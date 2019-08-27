#include "Vector.hxx"

const double PHYS::Vector::operator[] (const int index)
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

const PHYS::Vector PHYS::Vector::operator+ (const PHYS::Vector& other)
{
    PHYS::Vector _tmp = PHYS::Vector(_x1+other._x1, 
                                     _x2+other._x2,
                                     _x3+other._x3);
    
    return _tmp;
}

const PHYS::Vector PHYS::Vector::operator- (const PHYS::Vector& other)
{
    PHYS::Vector _tmp = PHYS::Vector(_x1-other._x1, 
                                     _x2-other._x2,
                                     _x3-other._x3);
    
    return _tmp;
}

const bool PHYS::Vector::operator== (const PHYS::Vector& other)
{
    return _x1 == other._x1 && _x2 == other._x2 && _x3 == other._x3;
}

const double PHYS::Vector::magnitude() const
{
    return pow(pow(_x1, 2)+pow(_x2, 2)+pow(_x3, 2), 0.5);
}

const PHYS::Vector PHYS::Vector::operator+= (const PHYS::Vector& other)
{
    PHYS::Vector _tmp = *this;
    return _tmp + other;
}

const PHYS::Vector PHYS::Vector::operator= (const PHYS::Vector& other)
{
    return other;
}