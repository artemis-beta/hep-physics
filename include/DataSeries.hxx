#ifndef __DATASERIES_HXX__
#define __DATASERIES_HXX__

#include "DynamicArray.hxx"
#include <iostream>

namespace PHYS
{
    namespace Data
    {
        template<typename index_type, typename data_type>
        class DataSeries
        {
            private:
                DynamicArray<index_type> _index = {};
                DynamicArray<data_type> _data = {};
            public:
                DataSeries<index_type, data_type>(){};
                DataSeries<index_type, data_type>(const std::initializer_list<data_type>&);
                DataSeries<index_type, data_type>(const DataSeries<index_type, data_type>& other) :
                    _data(other._data), _index(other._index) {}
                data_type operator[] (const int&) const;
                DataSeries<index_type, data_type>& operator= (DataSeries<index_type, data_type>);
                void push_back(const data_type& data_entry, const index_type index=-1)
                {
                    _data.push_back(data_entry);
                    
                    _index.push_back((index == -1) ? _index.size() : index);
                }

                int size() const {return _index.size();}

                void Print();

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
data_type PHYS::Data::DataSeries<index_type, data_type>::operator[] (const int& i) const
{
    return _data[i];
}

template<typename index_type, typename data_type>
PHYS::Data::DataSeries<index_type, data_type>::DataSeries(const std::initializer_list<data_type>& elements)
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

#endif