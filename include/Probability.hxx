#ifndef __PROB_HXX__
#define __PROB_HXX__

#include <vector>
#include <iostream>

namespace PHYS
{
    /*! @namespace PHYS::Probability
    
    Namespace covering all classes relating to probability objects
    
    @author K. Zarebski

    @copyright MIT License

    @date last modified 2020-01-31
    */
    namespace Probability
    {
        /*! @brief  Ratio Class
            @details    Class to represent a ratio
            @version    0.1.0
            @author     Kristian Zarebski
            @date 	    last modified 2020-01-31
            @copyright  MIT License
        */
        class Ratio
        {
            private:
                std::vector<double> _components;
            public:
                Ratio(std::vector<double> components) : _components(components) {}

                Ratio operator* (double& other) const
                {
                    Ratio _temp(*this);         
                    for(unsigned int i{0}; i<_temp._components.size(); ++i)
                    {
                        _temp._components[i] *= other;
                    }
                    return _temp;
                }

                Ratio operator* (Ratio& other) const
                {
                    Ratio _temp(*this);
                    std::vector<double> _temp_vec;
                    for(auto& i : _temp._components)
                    {
                        for(auto& j : other._components)
                        {
                            _temp_vec.push_back(i*j);
                        }
                    }

                    return Ratio(_temp_vec);
                }

                friend std::ostream& operator<< (std::ostream& os, const Ratio& r)
                {
                    for(unsigned int i{0}; i<r._components.size(); ++i)
                    {
                        if(i>0) os << ":";
                        os << r._components[i];
                    }
                    return os;
                }
        };
    };
};
#endif