#ifndef __PHYSVECTOR_HXX__
#define __PHYSVECTOR_HXX__

#include <stdexcept>
#include <cmath>

namespace PHYS
{
    class Vector
    {
        private:
            const double _x1, _x2, _x3;
        public:
            Vector(const double x, const double y, const double z) : 
                _x1(x), _x2(y), _x3(z) {}
            const double operator[] (const int index);
            const Vector operator+ (const Vector& other);
            const Vector operator- (const Vector& other);
            const bool operator== (const Vector& other);
            const Vector operator+= (const Vector& other);
            const double magnitude() const;
            const Vector operator= (const Vector& other);
    };
}

#endif