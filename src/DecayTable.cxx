#include "DecayTable.hxx"

Decay::Decay(std::vector<Particle> daughters, double probability, Particle _m)
{
	_prob      = probability;

	_daughters = daughters;	

	if(_m){_mother = _m;}
}

std::string Decay::getDecStr()
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

bool Decay::isValid(double num)
{
	return num < _prob;
}

void Decay::setMother(Particle _m)
{
	_mother = _m;
}

DecayTable::DecayTable(Particle _m)
{
	_mother = _m;
}

std::ostream& operator<< (std::ostream& os, Decay& d)
{
	os << d.getDecStr();
	
	return os;
}

void DecayTable::addDecay(Decay _decay)
{
	_decay.setMother(_mother);
	_brs.push_back(_decay.getBR());
	if(_cumul_brs.size() > 0){_cumul_brs.push_back(_cumul_brs[_cumul_brs.size()-1]+_decay.getBR());}
	else{_cumul_brs.push_back(_decay.getBR());}
	_decays.push_back(_decay);
}

Decay DecayTable::getRandom()
{
	srand (time(NULL));
        double rand_val = 9*rand()/1E10;
	std::cout << "BR: " << rand_val << std::endl;


	for(unsigned int i=0; i<_cumul_brs.size()-1; ++i)
	{
		for(unsigned int j=1; j<_cumul_brs.size(); ++j)
                {
		    std::cout << _cumul_brs[i] << "\t" << _cumul_brs[j] << std::endl;
		    if( rand_val > _cumul_brs[i] && rand_val < _cumul_brs[j] )
		    {
		    	return _decays[i];
		    }
	        }
	}

	return Decay();
}

void DecayTable::Print()
{
	for(unsigned int i=0; i<_decays.size(); ++i){std::cout << (_decays[i]).getDecStr() << std::endl;}
}
