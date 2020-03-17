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
        template<class index_type>
        class DataFrame
        {
            private:
                std::map<char, DataSeries<index_type, std::string>> _headers;
                DataSeries<index_type, std::vector<int>> _integer_vars;
                DataSeries<index_type, std::vector<float>> _float_vars;
                DataSeries<index_type, std::vector<double>> _double_vars;
                DataSeries<index_type, std::vector<bool>> _bool_vars;
                DataSeries<index_type, std::vector<std::string>> _str_vars;
                const int getSize();
            public:
                DataFrame<index_type>(){};
                void addColumnInt(const std::string&, std::initializer_list<int> integers);
                void addColumnBool(const std::string&, std::initializer_list<bool> booleans);
                void addColumnFloat(const std::string&, std::initializer_list<float> floats);
                void addColumnDouble(const std::string&, std::initializer_list<double> doubles);
                void addColumnString(const std::string&, std::initializer_list<std::string> strings);
                void head();
        };
    };
};

template<class index_type>
const int PHYS::Data::DataFrame<index_type>::getSize()
{
    int nentries = 0;
    if(_integer_vars.size() > 0) nentries = _integer_vars[0].size();
    else if(_float_vars.size() > 0) nentries = _float_vars[0].size();
    else if(_bool_vars.size() > 0) nentries = _bool_vars[0].size();
    else if(_double_vars.size() > 0) nentries = _double_vars[0].size();
    else if(_str_vars.size() > 0) nentries = _str_vars[0].size();
    
    return nentries;
}

template<class index_type>
void PHYS::Data::DataFrame<index_type>::addColumnInt(const std::string& header, std::initializer_list<int> elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    _integer_vars.push_back(DataSeries<index_type, int>(elements));
    _headers['I'].push_back(header);
}

template<class index_type>
void PHYS::Data::DataFrame<index_type>::addColumnDouble(const std::string& header, std::initializer_list<double> elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    _double_vars.push_back(elements);
    _headers['D'].push_back(header);
}

template<class index_type>
void PHYS::Data::DataFrame<index_type>::addColumnBool(const std::string& header, std::initializer_list<bool> elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    _bool_vars.push_back(elements);
    _headers['B'].push_back(header);
}

template<class index_type>
void PHYS::Data::DataFrame<index_type>::addColumnFloat(const std::string& header, std::initializer_list<float> elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    _float_vars.push_back(elements);
    _headers['F'].push_back(header);
}

template<class index_type>
void PHYS::Data::DataFrame<index_type>::addColumnString(const std::string& header, std::initializer_list<std::string> elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    _str_vars.push_back(elements);
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
        std::cout << i;

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