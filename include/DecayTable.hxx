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
		Decay(std::vector<Particle>, double);
		bool isValid(double);
		double getBR(){return _prob;}
		Particle* getMother(){return _mother;}
		void setMother(Particle);
		std::vector<Particle> getDaughters(){return _daughters;}

};

inline std::ostream &operator<<(std::ostream &os, Decay  &d)
{
	std::vector<Particle> _temp = d.getDaughters();
	os << d.getMother()->getName() << " -> ";
	for(int i{0}; i<_temp.size()-1; ++i)
	{
	    os << _temp[i].getName() << " ";
	}
	return os;
}


class DecayTable
{
	private:
		std::vector<Decay*> _decays_list;
		std::map<double, Decay*> _decays;
		typedef std::map<double, Decay*>::iterator It;
		Particle* _mother;
        public:
	        DecayTable(Particle);
		void addDecay(Decay);
		std::map<double, Decay*> getDecaysMap(){return _decays;}
		std::vector<Decay*> getDecays(){return _decays_list;}
		Decay* getRandom(double);
		void Print();
};	

#endif
