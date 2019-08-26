#include <iostream>
#include <string>
#include <iomanip>
#include "DecayTable.hxx"
#include "CommonParticles.hxx"
#include "KplusDecTable.hxx"

#include <vector>

using namespace HEP;

int main(int argc, char** argv)
{
	int nEvts = 100;

	if(argc > 0){nEvts = atoi(argv[1]);}

	std::cout << "Generating " << nEvts << " K+ Decays..." << std::endl;

	srand (time(NULL));
	std::map<std::string, int> _hist;

	for(int i{0}; i<nEvts; ++i)
	{
		const std::string _tmp =  KplusDecays.getRandom().getDecStr();
		if(_hist.find(_tmp) == _hist.end())
		{
			_hist[_tmp] = 1;
		}
		else
		{
			_hist[_tmp]++;
		}
	}

	for(std::map<std::string, int>::iterator iter = _hist.begin(); iter != _hist.end(); ++iter)
	{
		std::string key = iter->first;
		std::cout << iter->first << std::setw(20) <<  "\t|" << std::string(iter->second, '=') << std::endl;
	}
	
	return 0;
}
