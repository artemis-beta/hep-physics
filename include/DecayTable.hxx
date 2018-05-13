#ifndef __DECAYTABLE_HXX__
#define __DECAYTABLE_HXX__

#include "CommonParticles.hxx"
#include "Particle.hxx"
#include <vector>
#include <map>

class Particle;
class Decay
{
	private:
		double _prob;
		std::vector<Particle> _daughters;
		Particle * _mother;
	public:
		Decay();
		std::string getDecStr();
		Decay(std::vector<Particle>, double, Particle _mum=Particle());
		bool isValid(double);
		double getBR(){return _prob;}
		Particle* getMother(){return _mother;}
		void setMother(Particle);
		std::vector<Particle> getDaughters(){return _daughters;}

};

inline std::ostream &operator<<(std::ostream &os, Decay  &d)
{
	os << d.getDecStr();
	return os;
}


class DecayTable
{
	private:
		std::vector<std::string> _decays_list;
		std::map<double, Decay*> _decays;
		typedef std::map<double, Decay*>::iterator It;
		Particle* _mother;
        public:
	        DecayTable(Particle);
		void addDecay(Decay);
		std::map<double, Decay*> getDecaysMap(){return _decays;}
		std::vector<std::string> getDecays(){return _decays_list;}
		Decay* getRandom(double);
		void Print();
};	

#endif
