#ifndef __PHYSVECTOR_HXX__
#define __PHYSVECTOR_HXX__

#include <stdexcept>
#include <iostream>
#include <cmath>

namespace PHYS
{
    /*! @brief  Vector Class
	@details    Base class representing a vector 
	@version    0.1.0
	@author     Kristian Zarebski
	@date 	    last modified 2019-08-28
	@copyright  MIT License
    */
    class Vector
    {
        private:
            const double _x1, _x2, _x3;
        public:
            Vector(const double x1, const double x2, const double x3) : 
                _x1(x1), _x2(x2), _x3(x3) {}
            const double operator[] (const int index) const;
            const Vector operator+ (const Vector& other) const;
            const Vector operator- (const Vector& other) const;
            const bool operator== (const Vector& other) const;
            const Vector operator+= (const Vector& other) const;
            const Vector operator= (const Vector& other) const;
            const Vector operator/ (const double& other) const;
            
            const friend Vector operator* (const double& factor, const Vector& other)
            {
                Vector _tmp = {factor*other[0], factor*other[1], factor*other[2]};
                return _tmp;
            }

            friend std::ostream& operator<<(std::ostream& out, const Vector& other)
            {
                out << "[" << other[0] << ", " << other[1] << ", " << other[2] << "]";
                return out;
            }
    };

    /*! @brief  Cartesian Class
	@details    Subclass of Vector for Cartesian co-ordinates 
	@version    0.1.0
	@author     Kristian Zarebski
	@date 	    last modified 2019-08-28
	@copyright  MIT License
    */
    class Cartesian : public Vector
    {
        public:
            Cartesian(const double x, const double y, const double z) :
                Vector(x, y, z) {}
            Cartesian(const Vector& vec) :
                Vector(vec) {}
            const double magnitude() const;
            const Cartesian operator- (const Cartesian& other) const;
            const Cartesian operator+ (const Cartesian& other) const;
            /*! Converts the given co-ordinates to spherical polar form
            @returns Spherical
            */
            const Spherical inSphericalPolar() const;
    };

    /*! @brief  Spherical Class
	@details    Subclass of Vector for Spherical Polar co-ordinates 
	@version    0.1.0
	@author     Kristian Zarebski
	@date 	    last modified 2019-08-28
	@copyright  MIT License
    */
    class Spherical : public Vector
    {
        public:
            Spherical(const double r, const double theta, const double phi) :
                Vector(r, theta, phi) {}
            Spherical(const Vector& vec) :
                Vector(vec) {}
            /*! Converts the given co-ordinates to cartesian form
            @returns Cartesian
            */
            const Cartesian inCartesian() const;
            const double magnitude() const;
    };
}

#endif