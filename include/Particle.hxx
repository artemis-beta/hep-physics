#ifndef PARTICLE_HXX
#define PARTICLE_HXX

#include <iostream>
#include <math.h>

#include <string>
#include "LorentzVector.hxx"

namespace HEP
{
        /*! @brief  Particle Class
	@details    Class representing a single particle with information on mass and lifetime
	@version    0.1.0
	@author     Kristian Zarebski
	@date 	    last modified 2019-08-26 
	@copyright  MIT License
        */
        class Particle {
                private:
                        std::string name_="X";
                        std::string sign_="";
                        double mass_     = -1;
                        double lifetime_ = -1;
                        HEP::LorentzVector momentum_;
                public:
                        //! Default constructor with properties set to -1
                        Particle();
                        //! Construct a particle with a given name, sign, mass and lifetime. The energy will be taken to be the rest mass
                        Particle(std::string, std::string, double, double);
                        //! Construct a particle giving only the four momentum components
                        Particle(double,double,double,double);
                        //! Returns as a string the particle name
                        const std::string getName() const {return name_+sign_;}
                        //! Get the antiparticle partner of the current particle
                        const Particle anti() const;
                        //! Fire the particle at a given energy
                        void Fire(double);
                        //! Get the mass of the particle
                        const double M() const;
                        //! Get the azimuthal angle @f$ \phi @f$ of the particle trajectory
                        const double phi() const;
                        //! Get the rapidity @f$ y = \frac{1}{2}\log{\left(\frac{E+p_z}{E-p_z}\right)} @f$ of the particle
                        const double y() const;
                        //! Get the pseudorapidity @f$ \eta = -\log{\left(\tan\frac{\theta}{2}\right)} @f$ of the particle 
                        const double eta() const;
                        //! Get the angle @f$\theta @f$ of the particle trajectory in the @f$x-z @f$ plane
                        const double theta() const;
                        //! Get the LorentzVector of the given particle
                        const HEP::LorentzVector momentum() const;
                        //! Get the transverse momentum @f$p_T @f$ of the particle
                        const double PT() const;
                        //! Returns true if the particle has been initialised (does not have default blank values)
                        operator bool() const;
                        //! Output the particle properties to the ostream
                        friend std::ostream &operator<<(std::ostream &, Particle  &);
                };
}
#endif
