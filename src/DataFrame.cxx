#include "DataFrame.hxx"

const int PHYS::Data::DataFrame::getSize()
{
    int nentries = 0;
    if(_integer_vars.size() > 0) nentries = _integer_vars[0].size();
    else if(_float_vars.size() > 0) nentries = _float_vars[0].size();
    else if(_bool_vars.size() > 0) nentries = _bool_vars[0].size();
    else if(_double_vars.size() > 0) nentries = _double_vars[0].size();
    else if(_str_vars.size() > 0) nentries = _str_vars[0].size();
    
    return nentries;
}

void PHYS::Data::DataFrame::addColumnInt(const std::string& header, const std::vector<int>& elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    _integer_vars.push_back(elements);
    _headers['I'].push_back(header);
}

void PHYS::Data::DataFrame::addColumnDouble(const std::string& header, const std::vector<double>& elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    _double_vars.push_back(elements);
    _headers['D'].push_back(header);
}

void PHYS::Data::DataFrame::addColumnBool(const std::string& header, const std::vector<bool>& elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    _bool_vars.push_back(elements);
    _headers['B'].push_back(header);
}

void PHYS::Data::DataFrame::addColumnFloat(const std::string& header, const std::vector<float>& elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    _float_vars.push_back(elements);
    _headers['F'].push_back(header);
}

void PHYS::Data::DataFrame::addColumnString(const std::string& header, const std::vector<std::string>& elements)
{
    if(this->getSize() != 0 && elements.size() != this->getSize())
    {
        throw std::runtime_error("Number of Entries does not match existing branches");
    }
    _str_vars.push_back(elements);
    _headers['S'].push_back(header);
}

void PHYS::Data::DataFrame::head()
{
    std::vector<std::string> _labels;
    for(auto& l : _headers['I'])
    {
        _labels.push_back(l);
    }
    for(auto& l : _headers['D'])
    {
        _labels.push_back(l);
    }
    for(auto& l : _headers['F'])
    {
        _labels.push_back(l);
    }

    for(auto& l : _headers['B'])
    {
        _labels.push_back(l);
    }

    for(auto& l : _headers['S'])
    {
        _labels.push_back(l);
    }

    std::cout << "ID\t";

    for(auto& label : _labels) std::cout << label << "\t";

    std::cout << std::endl;

    const int limit = (this->getSize() > 10) ? 10 : this->getSize();

    for(int i{0}; i<limit; ++i)
    {
        std::cout << i;

        for(auto& v : _integer_vars)
        {
            std::cout << "\t" << v[i];
        }
        for(auto& v : _double_vars)
        {
            std::cout << "\t" << v[i];
        }
        for(auto& v : _float_vars)
        {
            std::cout << "\t" << v[i];
        }
        for(auto& v : _bool_vars)
        {
            std::cout << "\t" << v[i];
        }
        for(auto& v : _str_vars)
        {
            std::cout << "\t" << v[i];
        }
        std::cout << std::endl;
    }
}