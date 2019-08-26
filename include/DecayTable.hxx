#ifndef __DECAYTABLE_HXX__
#define __DECAYTABLE_HXX__

#include "CommonParticles.hxx"
#include "Particle.hxx"
#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>


namespace HEP
{
	class Particle;

	/*!	@brief      Decay Channel Class
		@details    Class describing a single particle decay with information on the 
					mother and daughter particles and branching ratio.
		@version	0.1.0
		@author     Kristian Zarebski
		@date 		last modified 2019-08-25 
		@copyright  MIT License
	*/
	class Decay
	{
		private:
			//! Probability of decay occuring (i.e. Branching Ratio)
			double _prob;
			//! Daughter particles
			std::vector<Particle> _daughters;
			//! Mother particle
			Particle  _mother = Particle();
		public:
			//! Blank decay object
			Decay(){};
			//! Get the decay description as a string
			const std::string getDecStr() const;
			//! Construct a decay with a given mother, daughters and branching ratio
			Decay(std::vector<Particle> daughters, double probability, Particle mother=Particle());
			//! Used to check probability of decay occuring against a threshold
			bool isValid(double threshold);
			//! Returns the branching ratio
			const double getBR() const{return _prob;}
			//! Returns the mother object
			const Particle getMother() const {return _mother;}
			//! Sets the mother particle
			void setMother(Particle& Mother);
			//! Returns a vector of the daughter particles
			const std::vector<Particle> getDaughters() const {return _daughters;}

	};

	std::ostream& operator<< (std::ostream& os, Decay& d);

	/*!	@brief      Decay Table Class
		@details    Class containing all decay channels for a given mother particle
					this is used to generate a decay at random
		@version	0.1.0
		@author     Kristian Zarebski
		@date 		last modified 2019-08-26
		@copyright  MIT License
	*/
	class DecayTable
	{
		private:
			/*! Branching ratios as keys
				@private */
			std::vector<double> _brs;
			//! Decays as list
			std::vector<Decay> _decays;
			//! Cumulative branching ratios
			std::vector<double> _cumul_brs;
			//! Common mother to all decays
			Particle _mother = Particle();
		public:
			//! Construct a decay table for a given mother particle
			DecayTable(const Particle& mother);
			//! Add a new decay to the decay table
			void addDecay(Decay& decay);
			//! Get the decays in decay tablea as a vector
			std::vector<Decay> getDecays(){return _decays;}
			//! Get a decay at random based on the branching ratios
			const Decay getRandom() const;
			//! Print the decay table
			void Print();
	};	
	/*! @example	KplusDecTable.hxx
		An example of the Decay Table class for K+*/
}
#endif
