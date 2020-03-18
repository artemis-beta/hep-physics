#ifndef __DATAFRAME_HXX__
#define __DATAFRAME_HXX__

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <type_traits>
#include <stdexcept>
#include <initializer_list>

#include "DataSeries.hxx"

namespace PHYS
{
    namespace Data
    {
        template<class T> struct types;
        template<> struct types<int> { using type = int; };
        template<> struct types<float> { using type = float; };
        template<> struct types<double> { using type = double; };
        template<> struct types<std::string> { using type = std::string; };
        template<> struct types<bool> { using type = bool; };
        template<class index_type>
        class DataFrame
        {
            private:
                DynamicArray<index_type> _index = {};
                std::map<char, DataSeries<index_type, std::string>> _headers;
                DataSeries<int, DataSeries<index_type, int>> _integer_vars = {};
                DataSeries<int, DataSeries<index_type, float>> _float_vars = {};
                DataSeries<int, DataSeries<index_type, double>> _double_vars = {};
                DataSeries<int, DataSeries<index_type, bool>> _bool_vars = {};
                DataSeries<int, DataSeries<index_type, std::string>> _str_vars = {};
                const int getSize();
            public:
                DataFrame<index_type>(){};
                void addColumnInt(const std::string&, std::initializer_list<int> integers);
                void addColumnBool(const std::string&, std::initializer_list<bool> booleans);
                void addColumnFloat(const std::string&, std::initializer_list<float> floats);
                void addColumnDouble(const std::string&, std::initializer_list<double> doubles);
                void addColumnString(const std::string&, std::initializer_list<std::string> strings);
                void head();
                DataSeries<index_type, int> getIntColumn(const std::string& label)
                { 
                    for(int i{0}; i < _headers['I'].size(); ++i)
                    {
                        if(_headers['I'][i] == label) return _integer_vars[i];
                    }
                    throw std::runtime_error("Could not find column '"+label+"' in integer variables");
                }
                DataSeries<index_type, double> getDoubleColumn(const std::string& label)
                { 
                    for(int i{0}; i < _headers['D'].size(); ++i)
                    {
                        if(_headers['D'][i] == label) return _double_vars[i];
                    }
                    throw std::runtime_error("Could not find column '"+label+"' in double variables");
                }
                DataSeries<index_type, float> getFloatColumn(const std::string& label)
                { 
                    for(int i{0}; i < _headers['F'].size(); ++i)
                    {
                        if(_headers['F'][i] == label) return _float_vars[i];
                    }
                    throw std::runtime_error("Could not find column '"+label+"' in float variables");
                }
                DataSeries<index_type, bool> getBoolColumn(const std::string& label)
                { 
                    for(int i{0}; i < _headers['B'].size(); ++i)
                    {
                        if(_headers['B'][i] == label) return _bool_vars[i];
                    }
                    throw std::runtime_error("Could not find column '"+label+"' in bool variables");
                }
                DataSeries<index_type, std::string> getStringColumn(const std::string& label)
                { 
                    for(int i{0}; i < _headers['S'].size(); ++i)
                    {
                        if(_headers['S'][i] == label) return _str_vars[i];
                    }
                    throw std::runtime_error("Could not find column '"+label+"' in string variables");
                }
        };
    };
};

template<class index_type>
const int PHYS::Data::DataFrame<index_type>::getSize()
{
    int nentries = 0;

    if(_bool_vars.size() >  0) nentries = _bool_vars[0].size();
    if(_float_vars.size() > 0 && _float_vars[0].size() > nentries) nentries = _float_vars[0].size();
    if(_double_vars.size() > 0 && _double_vars[0].size() > nentries) nentries = _double_vars[0].size();
    if(_bool_vars.size() > 0 && _bool_vars[0].size() > nentries) nentries = _bool_vars[0].size();
    if(_str_vars.size() > 0 && _str_vars[0].size() > nentries) nentries = _str_vars[0].size();
    return nentries;
}

template<class index_type>
void PHYS::Data::DataFrame<index_type>::addColumnInt(const std::string& header, std::initializer_list<int> elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    if(elements.size() == 0)
    {
        throw std::runtime_error("No values given");
    }
    _integer_vars.push_back(DataSeries<index_type, int>(elements));
    if(_index.size() == 0)_index = _integer_vars[_integer_vars.size()-1].getIndex();
    _headers['I'].push_back(header);
}

template<class index_type>
void PHYS::Data::DataFrame<index_type>::addColumnDouble(const std::string& header, std::initializer_list<double> elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }

    if(elements.size() == 0)
    {
        throw std::runtime_error("No values given");
    }

    _double_vars.push_back(DataSeries<index_type, double>(elements));
    if(_index.size() == 0)_index = _double_vars[_double_vars.size()-1].getIndex();
    _headers['D'].push_back(header);
}

template<class index_type>
void PHYS::Data::DataFrame<index_type>::addColumnBool(const std::string& header, std::initializer_list<bool> elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    if(elements.size() == 0)
    {
        throw std::runtime_error("No values given");
    }

    DataSeries<index_type, bool> _temp(elements);

    _bool_vars.push_back(_temp);
    if(_index.size() == 0)_index = _bool_vars[_bool_vars.size()-1].getIndex();
    _headers['B'].push_back(header);
}

template<class index_type>
void PHYS::Data::DataFrame<index_type>::addColumnFloat(const std::string& header, std::initializer_list<float> elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    if(elements.size() == 0)
    {
        throw std::runtime_error("No values given");
    }
    _float_vars.push_back(DataSeries<index_type, float>(elements));
    if(_index.size() == 0)_index = _float_vars[_float_vars.size()-1].getIndex();
    _headers['F'].push_back(header);
}

template<class index_type>
void PHYS::Data::DataFrame<index_type>::addColumnString(const std::string& header, std::initializer_list<std::string> elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    if(elements.size() == 0)
    {
        throw std::runtime_error("No values given");
    }
    _str_vars.push_back(DataSeries<index_type, std::string>(elements));
    if(_index.size() == 0)_index = _str_vars[_str_vars.size()-1].getIndex();
    _headers['S'].push_back(header);
}

template<class index_type>
void PHYS::Data::DataFrame<index_type>::head()
{
    std::vector<std::string> _labels;
    for(int i{0}; i < _headers['I'].size(); ++i)
    {
        _labels.push_back(_headers['I'][i]);
    }
    for(int i{0}; i < _headers['D'].size(); ++i)
    {
        _labels.push_back(_headers['D'][i]);
    }
    for(int i{0}; i < _headers['F'].size(); ++i)
    {
        _labels.push_back(_headers['F'][i]);
    }
    for(int i{0}; i < _headers['B'].size(); ++i)
    {
        _labels.push_back(_headers['B'][i]);
    }
    for(int i{0}; i < _headers['S'].size(); ++i)
    {
        _labels.push_back(_headers['S'][i]);
    }

    std::cout << "ID\t";

    for(auto& label : _labels) std::cout << label << "\t";

    std::cout << std::endl;

    const int limit = (this->getSize() > 10) ? 10 : this->getSize();

    for(int i{0}; i<limit; ++i)
    {
        std::cout << _index[i];

        for(int j{0}; j < _integer_vars.size(); ++j)
        {
            std::cout << "\t" << _integer_vars[j][i];
        }
        for(int j{0}; j < _double_vars.size(); ++j)
        {
            std::cout << "\t" << _double_vars[j][i];
        }
        for(int j{0}; j < _float_vars.size(); ++j)
        {
            std::cout << "\t" << _float_vars[j][i];
        }
        for(int j{0}; j < _bool_vars.size(); ++j)
        {
            std::cout << "\t" << _bool_vars[j][i];
        }
        for(int j{0}; j < _str_vars.size(); ++j)
        {
            std::cout << "\t" << _str_vars[j][i];
        }
        std::cout << std::endl;
    }
}

#endif