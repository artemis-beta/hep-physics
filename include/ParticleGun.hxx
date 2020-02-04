#ifndef __PARTICLE_GUN_HXX__
#define __PARTICLE_GUN_HXX__

#include "Particle.hxx"
#include "LorentzVector.hxx"
#include "Units.hxx"

#include <cmath>
#include <iostream>
#include <vector>

namespace PHYS
{
    /*! @namespace PHYS::Simulation
    
    Namespace containing all classes related to forced simulated processes
    such as particle guns
    
    @author K. Zarebski

    @copyright MIT License

    @date last modified 2020-01-31
    */
    namespace Simulation
    {
        class ParticleGun
        {
            private:
                const PHYS::Particle* _particle;
                PHYS::LorentzVector _gun_momentum = PHYS::LorentzVector(0, 0, 0, 0);
                PHYS::LorentzVector _calculate_vector(const std::vector<double>);
            public:
                ParticleGun(const PHYS::Particle* particle) : _particle(particle) {}
                ParticleGun(const PHYS::Particle*, double, double, double);
                const PHYS::LorentzVector getFourVector() const {return _gun_momentum;}
                const PHYS::Particle* getParticle() const {return _particle;}

                friend std::ostream& operator<< (std::ostream& o, const ParticleGun& p);
        };
    }
}

#endif