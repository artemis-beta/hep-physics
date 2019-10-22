#ifndef __DATAFRAME_HXX__
#define __DATAFRAME_HXX__

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <type_traits>
#include <stdexcept>

namespace PHYS
{
    namespace Data
    {
        class DataFrame
        {
            private:
                std::map<char,std::vector<std::string>> _headers;
                std::vector<std::vector<int>> _integer_vars;
                std::vector<std::vector<float>> _float_vars;
                std::vector<std::vector<double>> _double_vars;
                std::vector<std::vector<bool>> _bool_vars;
                std::vector<std::vector<std::string>> _str_vars;
                const int getSize();
            public:
                void addColumnInt(const std::string&, const std::vector<int>&);
                void addColumnBool(const std::string&, const std::vector<bool>&);
                void addColumnFloat(const std::string&, const std::vector<float>&);
                void addColumnDouble(const std::string&, const std::vector<double>&);
                void addColumnString(const std::string&, const std::vector<std::string>&);

                void head();
        };
    };
};

#endif