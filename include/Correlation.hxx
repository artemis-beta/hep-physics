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

        template<typename T>
        const PHYS::Data::DynamicArray<double> _spearman_rank(const PHYS::Data::DynamicArray<T>& array);

        template<typename T>
        const double SpearmanRankCorrelation(const PHYS::Data::DynamicArray<T>& item1, const PHYS::Data::DynamicArray<T>& item2);
    };
};

template<typename T>
const double PHYS::Statistics::PearsonCorrelation(const PHYS::Data::DynamicArray<T>& item1, const PHYS::Data::DynamicArray<T>& item2, const int n_obs)
{
    if(item1.size() != item2.size()) return -1;
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

template<typename T>
const double PHYS::Statistics::SpearmanRankCorrelation(const PHYS::Data::DynamicArray<T>& item1, const PHYS::Data::DynamicArray<T>& item2)
{
    if(item1.size() != item2.size()) return -1;
    PHYS::Data::DynamicArray<double> _rank1 = _spearman_rank(item1), _rank2 = _spearman_rank(item2);

    double _dsq = 0;

    for(int i{0}; i < _rank1.size(); ++i) _dsq += pow(_rank1[i]-_rank2[i],2);

    return 1 - (6*_dsq)/(_rank1.size()*(pow(_rank1.size(),2)-1));
}

template<typename T>
const PHYS::Data::DynamicArray<double> PHYS::Statistics::_spearman_rank(const PHYS::Data::DynamicArray<T>& array)
{
    PHYS::Data::DynamicArray<double> _rank = PHYS::Data::DynamicArray<double>().zeros(array.size());

    for(int i{0}; i < array.size(); ++i)
    {
        for(int j{0}; j < array.size(); ++j)
        {
            if(i == j) continue;
            if(array[j] == array[i])
            {
                _rank[j] = _rank[j]+0.5;
            }
            else if(array[j] < array[i])
            {
                _rank[j] = _rank[j] + 1;
            }
        }
    }

    return _rank;
}

#endif