#ifndef __DECAYTABLE_HXX__
#define __DECAYTABLE_HXX__

#include "CommonParticles.hxx"
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
		std::vector<Particle> getDaughters(){return _daughters;}

};

inline std::ostream &operator<<(std::ostream &os, Decay  &d)
{
	std::vector<Particle> _temp = d.getDaughters();
	os << d.getMother() << " -> ";
	for(int i{0}; i<_temp.size(); ++i)
	{
//	    os << _temp[i] << " ";
	}
	return os;
}


class DecayTable
{
	private:
		std::map<double, Decay*> _decays;
		typedef std::map<double, Decay*>::iterator It;
        public:
	        DecayTable();
		void addDecay(Decay);
		std::map<double, Decay*> getDecays(){return _decays;}
		Decay* getRandom(double);
};	

#endif
