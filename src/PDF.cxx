#include "PDF.hxx"

const std::vector<double> PHYS::ProbabilityDensityFunction::generate(const int nevts)
{
    std::vector<double> _events;
    for(int i{0}; i < nevts; ++i)
    {
        double _randval = rand() % 100000;
        _events.push_back(_f(_randval/1E5, _params)); 
    }
    return _events;
}