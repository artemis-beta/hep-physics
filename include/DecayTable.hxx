#ifndef __DECAYTABLE_HXX__
#define __DECAYTABLE_HXX__

#include "CommonParticles.hxx"
#include "Particle.hxx"
#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>

class Particle;
class Decay
{
	private:
		double _prob;
		std::vector<Particle> _daughters;
		Particle  _mother = Particle();
	public:
		Decay(){};
		std::string getDecStr();
		Decay(std::vector<Particle>, double, Particle _mum=Particle());
		bool isValid(double);
		double getBR(){return _prob;}
		Particle getMother(){return _mother;}
		void setMother(Particle);
		std::vector<Particle> getDaughters(){return _daughters;}

};

std::ostream& operator<< (std::ostream& os, Decay& d);

class DecayTable
{
	private:
		std::vector<double> _brs;
		std::vector<Decay> _decays;
		std::vector<double> _cumul_brs;
		Particle _mother = Particle();
        public:
	        DecayTable(Particle);
		void addDecay(Decay);
		std::vector<Decay> getDecays(){return _decays;}
		Decay getRandom();
		void Print();
};	

#endif
