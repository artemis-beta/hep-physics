#ifndef __CLASSICAL_HXX__
#define __CLASSICAL_HXX__

#include <vector>
#include <string>

#include "Units.hxx"
#include "Vector.hxx"

namespace PHYS
{
    //! Force on a classical body
    typedef Vector Force;

    //! Cartesian Co-ordinates
    typedef Vector Coordinate;

    /*! @brief  Object Class
	@details    Class to describe all basic objects used in the classical mechanics library
	@version    0.1.0
	@author     Kristian Zarebski
	@date 	    last modified 2019-08-27
	@copyright  MIT License
        */
    class Object
    {
        private:
            std::string _name;
            Coordinate _position;
        public:
            Object(const std::string label="", const Coordinate position= {-999,-999,-999}) :
                _name(label), _position(position) {}
            void Place(const Coordinate& c){_position = c;}
            const std::string getName() const {return _name;}
            const Coordinate getPosition() const {return _position;}
    };

    /*! @brief  Simple Body Class
	@details    Subclass of Object representing a simple object represented as a sphere in the co-ordinate system
	@version    0.1.0
	@author     Kristian Zarebski
	@date 	    last modified 2019-08-27
	@copyright  MIT License
        */
    class SimpleBody : public Object
    {
        private:
            const double _mass;
            const double _radius;
            std::vector<Force> _forces;
        public:
            /*! Construct a simple body, additional arguments are optional
            @param label Name of simple body
            @param mass If specified, sets the mass of the body
            @param radius If specified, sets the radius of the sphere representing the body
            */
            SimpleBody(const std::string label, const double mass=1.*PHYS::Units::kg, const double radius=1.*PHYS::Units::cm) :
                _mass(mass),
                _radius(radius),
                Object(label){}
            /*! Apply a force to the body
            @param f Force in the form of a Vector
            @returns void
            */
            void applyForce(const Force& f);
            /*! Resolve all applied forces to give the resultant force
            @returns Force (Vector)*/
            const Force resolve() const;  
    };

    /*! @brief  Spring Class
	@details    Subclass of Object representing a spring
	@version    0.1.0
	@author     Kristian Zarebski
	@date 	    last modified 2019-08-27
	@copyright  MIT License
        */
    class Spring : public Object
    {
        private:
            const double _spring_constant;
            const double _length_at_rest;
            const Coordinate _displacement = {0,0,0};
        public:
            Spring(const std::string label, const double spring_constant, const double length) :
                _spring_constant(spring_constant),
                _length_at_rest(length),
                Object(label){}
            void attach(Object& other);            
    };
}

#endif