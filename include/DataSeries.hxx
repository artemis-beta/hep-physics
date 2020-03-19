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
                data_type operator[] (const index_type&) const;
                data_type iloc(const int& i) const {return _data[i];}
                DataSeries<index_type, data_type>& operator= (DataSeries<index_type, data_type>);
                void push_back(const data_type& data_entry)
                {
                    _data.push_back(data_entry);
                    
                    index_type _current = (_index.size() < 1) ? index_type(_start-index_type(_index_interval)) : _index[_index.size()-1];
                    _index.push_back(_current+_index_interval);
                }

                void insert(const index_type& index, const data_type& value);

                int size() const {return _index.size();}

                void Print();
                
                DataSeries<index_type, data_type> append(const DataSeries& other);
                DataSeries<index_type, data_type> cumsum() const;
                DataSeries<index_type, data_type> sort_byvalue() const;
                double corr(const DataSeries<index_type, data_type>& other, CorrelationMethod method=CorrelationMethod::Pearson) const;

                DynamicArray<index_type> getIndex() const {return _index;}

                friend std::ostream& operator<< (std::ostream& o, const DataSeries& d)
                {
                    o << "DataSeries" << "[(";
                    for(unsigned int i{0}; i < d.size(); ++i)
                    {
                        o << d.iloc(i);
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
data_type PHYS::Data::DataSeries<index_type, data_type>::operator[] (const index_type& i) const
{
    if(*typeid(index_type).name() == 'i') return _data[int(i)];

    for(int j{0}; j < _index.size(); ++j)
    {
        if(_index[j] == i) return _data[j];
    }

    throw std::runtime_error("Invalid index");
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

template<typename index_type, typename data_type>
void PHYS::Data::DataSeries<index_type, data_type>::insert(const index_type& position, const data_type& value)
{
    for(int i{0}; i < size()-1; ++i)
    {
        if(_index[i] <= position && _index[i+1] > position)
        {
            _index.insert(i, position);
            _data.insert(i, value);
            break;
        }
    }

    if(*typeid(index_type).name() == 'i')
    {
        _index = DynamicArray<index_type>();
        for(int i{0}; i < _data.size(); ++i) _index.push_back(i);
    }

}

template<typename index_type, typename data_type>
PHYS::Data::DataSeries<index_type, data_type> PHYS::Data::DataSeries<index_type, data_type>::sort_byvalue() const
{
    PHYS::Data::DataSeries<index_type, data_type> _temp;

    _temp._index.push_back(_index[0]);
    _temp._data.push_back(_data[0]);

    for(int i{1}; i < _index.size(); ++i)
    {
        if(_temp._data.size() == 1)
        {
            if(_data[i] > _temp._data[0])
            {
                _temp.push_back(_data[i]);
            }
            else
            {
                _temp._data = DynamicArray<data_type>({_data[i],_temp._data[0]});
                _temp._index = DynamicArray<index_type>({_index[i], _temp._index[0]});
            }

        }
        else
        {
            for(int j{0}; j < _temp.size(); ++j)
            {
                if(_data[i] <= _temp._data[j])
                {
                    _temp.insert(j, _data[i]);
                    break;
                }

                else if(j == _temp.size()-1)
                {
                    _temp.push_back(_data[i]);
                }
            }
        }
    }

    return _temp;
} 

#endif