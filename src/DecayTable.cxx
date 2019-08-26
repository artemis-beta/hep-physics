#include "DecayTable.hxx"

HEP::Decay::Decay(std::vector<Particle> daughters, double probability, Particle _m)
{
	_prob      = probability;

	_daughters = daughters;	

	if(_m){_mother = _m;}
}

const std::string HEP::Decay::getDecStr() const
{
	std::string out_str="";
	out_str = _mother.getName();
        out_str +=	" -> ";
	for(unsigned int i{0}; i<_daughters.size(); ++i)
	{  
	   out_str += _daughters[i].getName();
	   out_str += " ";
	}
	return out_str;
}

bool HEP::Decay::isValid(double num)
{
	return num < _prob;
}

void HEP::Decay::setMother(Particle& _m)
{
	_mother = _m;
}

HEP::DecayTable::DecayTable(const Particle& _m)
{
	_cumul_brs.push_back(0);
	_mother = _m;
}

std::ostream& operator<< (std::ostream& os, HEP::Decay& d)
{
	os << d.getDecStr();
	
	return os;
}

void HEP::DecayTable::addDecay(Decay& _decay)
{
	_decay.setMother(_mother);
	_brs.push_back(_decay.getBR());
	if(_cumul_brs.size() > 0){_cumul_brs.push_back(_cumul_brs[_cumul_brs.size()-1]+_decay.getBR());}
	else{_cumul_brs.push_back(_decay.getBR());}
	_decays.push_back(_decay);
}

const HEP::Decay HEP::DecayTable::getRandom() const
{
        double rand_val = rand()*1E10/RAND_MAX;
	rand_val /= 1E10;
	for(unsigned int i=0; i<_cumul_brs.size()-1; ++i)
	{
            if( rand_val > _cumul_brs[i] && rand_val < _cumul_brs[i+1] )
            {
		return _decays[i];
            }
	}

	return Decay();
}

void HEP::DecayTable::Print()
{
	for(unsigned int i=0; i<_decays.size(); ++i){std::cout << (_decays[i]).getDecStr() << std::endl;}
}
