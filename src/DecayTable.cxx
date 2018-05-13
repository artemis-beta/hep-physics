#include "DecayTable.hxx"

Decay::Decay(std::vector<Particle> daughters, double probability)
{
	_prob      = probability;
	_daughters = daughters;
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
	std::cout << _mother->getName() << std::endl;
}


void DecayTable::addDecay(Decay _decay)
{
	_decay.setMother(*_mother);
	_decays[_decay.getBR()] = &_decay;
	_decays_list.push_back(&_decay);
	std::cout << _decays_list[0]->getMother()->getName() << std::endl;
}

Decay* DecayTable::getRandom(double num)
{
	double linear = rand()*1.0/RAND_MAX;
	return _decays.upper_bound(linear)->second;
}

void DecayTable::Print()
{
    if(_decays_list.size() < 1){return;}
    for(int i{0}; i<_decays_list.size()-1; ++i)
    {
	    std::cout << *_decays_list[i] << std::endl;
    }
}
