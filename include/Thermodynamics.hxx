#ifndef __THERMODYNAMICS_HXX__
#define __THERMODYNAMICS_HXX__

#include "Vector.hxx"
#include "CommonMolecules.hxx"

namespace PHYS
{
    /*! @brief  Container Class
	@details    Class representing a container for holding a compound
	@version    0.1.0
	@author     Kristian Zarebski
	@date 	    last modified 2019-08-28
	@copyright  MIT License
        */

    typedef std::map<const PHYS::Molecules::Molecule, double> Occupancy;

    class Container
    {
        private:
            const Cartesian _dimensions;
            Occupancy _contents;// = {{PHYS::Molecules::Vacuum, -1}};
            bool is_empty = true;
            double _temperature = 298*PHYS::Units::K;
        public:
            /*! Define a new container, the starting temperature is set to be room temperature at 298K
            @param x  length
            @param y  width
            @param z  height
            */
            Container(const double x, const double y, const double z) :
                _dimensions(Vector(x,y,z))
                {}
                /*! Fill container with a molecule
                @param molecule The molecule to add to the container
                @param quantity The amount of the molecule to add by mass*/
            void Fill(const PHYS::Molecules::Molecule&  molecule, const double mass);

            /*! Set temperature within container
            @param temperature Set the temperature to a value
            */
            void setTemperature(const double temperature){_temperature = temperature;};
            const double getVolume() const {return _dimensions.magnitude();}
            const double getNMoles(const PHYS::Molecules::Molecule& molecule);
            const double getPressure();
    };
}

#endif