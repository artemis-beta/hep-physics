#ifndef __DATASERIES_HXX__
#define __DATASERIES_HXX__

#include "DynamicArray.hxx"
#include "Correlation.hxx"
#include <iostream>

namespace PHYS
{
    namespace Data
    {
        enum class CorrelationMethod
        {
            Pearson,
            Kendall,
            Spearman,
            Callable
        };
        template<typename index_type, typename data_type>
        class DataSeries
        {
            private:
                const index_type _index_interval, _start;
                DynamicArray<index_type> _index = {};
                DynamicArray<data_type> _data = {};
            public:
                DataSeries<index_type, data_type>(index_type interval = index_type(1), index_type start_point = index_type(0)) : _index_interval(interval), _start(start_point) {};
                DataSeries<index_type, data_type>(const std::initializer_list<data_type>&, index_type interval = index_type(1), index_type start_point = index_type(0));
                DataSeries<index_type, data_type>(const DataSeries<index_type, data_type>& other, index_type interval = index_type(1), index_type start_point = index_type(0)) :
                    _index_interval(interval), _start(start_point), _data(other._data), _index(other._index) {}
                data_type operator[] (const int&) const;
                DataSeries<index_type, data_type>& operator= (DataSeries<index_type, data_type>);
                void push_back(const data_type& data_entry)
                {
                    _data.push_back(data_entry);
                    
                    index_type _current = (_index.size() < 1) ? index_type(_start-index_type(_index_interval)) : _index[_index.size()-1];
                    _index.push_back(_current+_index_interval);
                }

                int size() const {return _index.size();}

                void Print();
                
                DataSeries<index_type, data_type> append(const DataSeries& other);
                DataSeries<index_type, data_type> cumsum() const;
                double corr(const DataSeries<index_type, data_type>& other, CorrelationMethod method=CorrelationMethod::Pearson) const;

                DynamicArray<index_type> getIndex() const {return _index;}

                friend std::ostream& operator<< (std::ostream& o, const DataSeries& d)
                {
                    o << "DataSeries" << "[(";
                    for(unsigned int i{0}; i < d.size(); ++i)
                    {
                        o << d[i];
                        if(i < d.size()-1) o << ", ";
                    }

                    o << "), '" << typeid(data_type).name() << "'";
                    o << ", index='" << typeid(index_type).name() << "'";
                    
                    if(d._data._label != "") o << ", label='" << d._data._label << "'";
                    
                    o << "]";

                    return o;
                }
        };
    };
};

template<typename index_type, typename data_type>
PHYS::Data::DataSeries<index_type, data_type> PHYS::Data::DataSeries<index_type, data_type>::cumsum() const
{
    PHYS::Data::DataSeries<index_type, data_type> _temp(*this);
    for(int i{1}; i < _temp.size(); ++i)
    {
        _temp._data._container[i] = _temp._data._container[i]+_temp._data._container[i-1];
    }

    return _temp;
}

template<typename index_type, typename data_type>
data_type PHYS::Data::DataSeries<index_type, data_type>::operator[] (const int& i) const
{
    return _data[i];
}

template<typename index_type, typename data_type>
PHYS::Data::DataSeries<index_type, data_type>::DataSeries(const std::initializer_list<data_type>& elements, index_type interval, index_type start_point) : 
    _index_interval(interval), _start(start_point)
{
    for(auto& element : elements)
    {
        push_back(element);
    }

}

template<typename index_type, typename data_type>
void PHYS::Data::DataSeries<index_type, data_type>::Print()
{
    std::cout << "DataSeries (";
    std::cout << typeid(data_type).name();
    std::cout << ")\n";
    for(int i{0}; i < _index.size(); ++i)
    {
        std::cout << _index[i] << "\t" << _data[i] << std::endl;
    }

    std::cout << std::endl;
}

template<typename index_type, typename data_type>
PHYS::Data::DataSeries<index_type, data_type>& PHYS::Data::DataSeries<index_type, data_type>::operator= (DataSeries<index_type, data_type> other)
{
    std::swap(_index, other._index);
    std::swap(_data, other._data);
    return *this;
}

template<typename index_type, typename data_type>
PHYS::Data::DataSeries<index_type, data_type> PHYS::Data::DataSeries<index_type,data_type>::append(const PHYS::Data::DataSeries<index_type, data_type>& other)
{
    DataSeries<index_type, data_type> _temp(*this);
    for(int i{0}; i < other._index.size(); ++i)
    {
        _temp._data.push_back(other._data[i]);
        index_type _current = _temp._index[_temp._index.size()-1];
        _temp._index.push_back(_current+other._index_interval);
    }

    return _temp;
}

template<typename index_type, typename data_type>
double PHYS::Data::DataSeries<index_type, data_type>::corr(const DataSeries<index_type, data_type>& other, PHYS::Data::CorrelationMethod method) const
{
    if(method == CorrelationMethod::Pearson) return PHYS::Statistics::PearsonCorrelation(_data, other._data);
    return -1;
}

#endif