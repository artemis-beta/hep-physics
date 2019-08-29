#ifndef __CLASSICAL_HXX__
#define __CLASSICAL_HXX__

#include <vector>
#include <string>
#include <map>
#include <iostream>

#include "Units.hxx"
#include "Vector.hxx"

namespace PHYS
{
    //! Force on a classical body
    typedef Cartesian Force;

    //! Cartesian Co-ordinates
    typedef Cartesian Coordinate;

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
            std::vector<Force> _forces;
        public:
            Object(const std::string label="", const Coordinate position= {-999,-999,-999}) :
                _name(label), _position(position) {}
            void Place(const Coordinate& c){_position = c;}
            const std::string getName() const {return _name;}
            const Coordinate getPosition() const {return _position;}
            /*! Apply a force to the body
            @param f Force in the form of a Vector
            @returns void
            */
            void applyForce(Force& f);
            /*! Resolve all applied forces to give the resultant force
            @returns Force (Vector)*/
            const Force resolve() const;  
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
        public:
            /*! Construct a simple body, additional arguments are optional
            @param label Name of simple body
            @param mass If specified, sets the mass of the body
            @param radius If specified, sets the radius of the sphere representing the body
            */
            SimpleBody(const std::string label, const double mass=1.*PHYS::Units::kg, const double radius=1.*PHYS::Units::cm) :
                Object(label),
                _mass(mass),
                _radius(radius)
                {}
            const double M() const {return _mass;}
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
            Coordinate _points[2] = {{0,0,0}, {0,1,0}};
            std::vector<Object*> _attachments;
        public:
            /*! Construct a spring within the workspace
            @param label  Name of the spring
            @param spring_constant The spring constant @f$k@f$ of the spring
            @param length The unextended spring length
            @returns Spring
            */
            Spring(const std::string label, const double spring_constant, const double length) :
                Object(label),
                _spring_constant(spring_constant),
                _length_at_rest(length)
                {
                    _points[0] = getPosition(); 
                }
            const Force forceSpring();
            /*! Attach the spring to another object
            @param other Another object of type Object
            */
            void Attach(Object* other);
            //! Update the Spring co-ordinates based on attached objects
            void Update();          
    };

    class SUVATSolver
    {
        private:
            std::map<char, double> _variables;
            //! @f$ a = \frac{v-u}{t}@f$
            void SUVAT1();
            //! @f$ s = ut + \frac{1}{2}at^2@f$
            void SUVAT2();
            //! @f$ s = \frac{u+v}{2}t @f$
            void SUVAT3();
            //! @f$ v^2 = u^2 +2as @f$
            void SUVAT4();
        public:
            /*! Use SUVAT to find unknown variables, where unknowns are assigned the value of @c 1E-38
            @param s Displacement
            @param u Initial Velocity
            @param v Final Velocity
            @param a Acceleration
            @param t Time
            */
            SUVATSolver(const double s=1E-38, const double u=1E-38, const double v=1E-38, const double a=1E-38, const double t=1E-38);
            /*! Access/assign to a variable, returns set value of variable
            @param var The variable to access
            @param val If stated, set the variable to be the value
            @returns double*/
            double& operator()(const char& var, const double val=1E-38);

            friend std::ostream& operator<< (std::ostream& o, const SUVATSolver& solver)
            {
                std::string units[5] = {"m", "m/s", "m/s", "m/s^2", "s"};
                int i = 0;
                for(const auto& var : solver._variables)
                {
                    const char c = var.first;
                    const double val = var.second;

                    o << c << ": " << val << " " << units[i] << std::endl;
                    ++i;
                }
                return o;
            }
    };
}

#endif