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

void DecayTable::addDecay(Decay _decay)
{
	_decays[_decay.getBR()] = &_decay;
}

Decay* DecayTable::getRandom(double num)
{
	double linear = rand()*1.0/RAND_MAX;
	return _decays.upper_bound(linear)->second;
}
