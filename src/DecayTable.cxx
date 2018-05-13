#include "DecayTable.hxx"

Decay::Decay(std::vector<Particle> daughters, double probability, Particle _m)
{
	_prob      = probability;
	_daughters = daughters;
	if(_m){_mother = &_m;}
}

std::string Decay::getDecStr()
{
	Particle mother = *this->getMother();
	std::string out_str="";
	if(!mother){std::cout << "WARNING: Could not print decay, no valid mother found." << std::endl; exit(0);}
	std::vector<Particle> _temp = this->getDaughters();
	out_str = mother.getName();
        out_str +=	" -> ";
	for(int i{0}; i<_temp.size(); ++i)
	{  
	   if(!_temp[i]){std::cout << "WARNING: Could not print decay, no valid daughter found." << std::endl; exit(0);}
	   out_str += _temp[i].getName();
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
	_mother = &_m;
}

DecayTable::DecayTable(Particle _m)
{
	_mother = &_m;
}


void DecayTable::addDecay(Decay _decay)
{
	_decay.setMother(*_mother);
	_decays[_decay.getBR()] = &_decay;
	_decays_list.push_back(_decay.getDecStr());
}

Decay* DecayTable::getRandom(double num)
{
	double linear = rand()*1.0/RAND_MAX;
	return _decays.upper_bound(linear)->second;
}

void DecayTable::Print()
{
    if(_decays_list.size() < 1){return;}
    for(int i{0}; i<_decays_list.size(); ++i)
    {
	    std::cout << _decays_list[i] << std::endl;
    }
}
