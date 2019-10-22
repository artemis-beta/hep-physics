#ifndef __HISTO_HXX__
#define __HISTO_HXX__

#include <vector>
#include <iostream>
#include <string>

namespace PHYS
{
    /*! @namespace PHYS::Data
    
    Namespace containing all data handling classes
    
    @author K. Zarebski

    @copyright MIT License

    @date last modified 2019-10-22
    */
    namespace Data
    {
        typedef std::vector<double> Bins;

        /*! @brief  Histogram Class
        @details    Class to produce a Histogram for storing data
        @version    0.1.0
        @author     Kristian Zarebski
        @date 	    last modified 2019-10-22
        @copyright  MIT License
        */
        class Histogram
        {
            private:
                Bins _bins;
                std::vector<int> _entries;
            public:
                Histogram(const int nbins, const double x_low, const double x_high);
                Histogram(const Bins bins) : _bins(bins)
                {
                    for(int i{0}; i<bins.size(); ++i) _entries.push_back(0);
                }
                template <typename T>
                void Fill(const T&);
                void consolePlot();
        };
    };
};

PHYS::Data::Histogram::Histogram(const int nbins, const double x_low, const double x_high)
{
    const double interval = (x_high-x_low)/nbins;

    for(int i{0}; i<nbins; ++i)
    {
        _bins.push_back(i*interval);
        _entries.push_back(0);
    }
}

template <typename T>
void PHYS::Data::Histogram::Fill(const T& value)
{
    const double _val = static_cast<double>(value);
    for(int i{0}; i<_bins.size()-1; ++i)
    {
        if(_val > _bins[i] && _val < _bins[i+1])
        {
            _entries[i]++;
        }
    }
}

void PHYS::Data::Histogram::consolePlot()
{
    for(int i{0}; i<_bins.size(); ++i)
    {
        std::cout << _bins[i] << "\t| " << std::endl;
        std::cout << " " << "\t| " << std::string(_entries[i], '=') << std::endl;
    }
}

#endif