#ifndef __PHYSARRAY_HXX__
#define __PHYSARRAY_HXX__

#include "Container.hxx"

namespace PHYS
{
    namespace Data
    {
        template<typename T>
        /*! @brief  Array Class
        @details    A fixed size container class (clone of ContainerClass)
        @version    0.1.0
        @author     Kristian Zarebski
        @date 	    last modified 2020-01-31
        @copyright  MIT License
        */
        class Array : public Container<T>
        {
            public:
                Array(const std::string label="") :
                    Container<T>(label) {}
                Array(const int &size, const std::string label="") :
                    Container<T>(size, label, "Array") {}
                Array(const std::initializer_list<T>& elements, const std::string label="") :
                    Container<T>(elements, label, "Array") {}
        };
    };
};

#endif