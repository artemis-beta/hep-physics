#ifndef __CORRELATION_HXX__
#define __CORRELATION_HXX__

#include "DynamicArray.hxx"

#include <cmath>

namespace PHYS
{
    namespace Statistics
    {
        template<typename T>
        const double PearsonCorrelation(const PHYS::Data::DynamicArray<T>& item1, const PHYS::Data::DynamicArray<T>& item2, const int n_obs=-1);
    };
};

template<typename T>
const double PHYS::Statistics::PearsonCorrelation(const PHYS::Data::DynamicArray<T>& item1, const PHYS::Data::DynamicArray<T>& item2, const int n_obs)
{
    const int _limit = (n_obs == -1) ? ((item1.size() > item2.size()) ? item2.size() : item1.size()) : n_obs;

    double _xy = 0, 
           _x  = 0,
           _y  = 0,
           _xx = 0,
           _yy = 0;

    for(int i{0}; i < _limit; ++i)
    {
        _x  += item1[i];
        _y  += item2[i];
        _xy += item1[i]*item2[i];
        _xx += item1[i]*item1[i];
        _yy += item2[i]*item2[i];       
    }

    const double _numerator = _limit*_xy-_x*_y;
    const double _denominator = sqrt(_limit*_xx-pow(_x,2))*sqrt(_limit*_yy-pow(_y,2));

    return _numerator/_denominator;
}

#endif